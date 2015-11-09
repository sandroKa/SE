#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "gui_addtransaction.h"
#include "gui_error.h"
#include <iostream>

GUI::MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->date_from->setDate(QDate::currentDate().addMonths(-1));
    ui->date_to->setDate(QDate::currentDate());
    household = new logic::Household();
    QString ColumnName[] = {"Reason", "Comment", "Date", "Category", "Payment_Method", "Value"};
    ui->tbl_Overview->setColumnCount(6);
    ui->tbl_Overview->setRowCount(0);
    ui->tbl_Overview->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for(int i = 0; i < 6; i++)
        {
            ui->tbl_Overview->setHorizontalHeaderItem(i, new QTableWidgetItem(ColumnName[i]));
        }

    QStringList list=(QStringList()<<"10"<<"20"<<"50");
    ui->cmb_DataCount->addItems(list);
    refreshui();
}

GUI::MainWindow::~MainWindow()
{
    delete ui;
    delete household;
}

int GUI::MainWindow::start(QApplication *qApplication)
{
    GUI::Login Login(household, this);
    int exec = Login.exec();
    if(exec == QDialog::Accepted)
    {
        show();
        filter();
        return qApplication->exec();
    }
    else
    {
        return exec;
    }
}

void GUI::MainWindow::filter()
{
    ui->tbl_Overview->clearContents();

    logic::transaction filterTrans;
    filterTrans.setDate_from(ui->date_from->date().toString("yyyy-MM-dd"));
    filterTrans.setDate_to(ui->date_to->date().toString("yyyy-MM-dd"));
    filterTrans.setUserID(1);
    filterTrans.setIndex(ui->cmb_DataCount->currentText().toInt());
    filterTrans.setCategory(ui->cmb_Cat->currentText() == "<none>" ? "" : ui->cmb_Cat->currentText());
    household->retrieveTrans(filterTrans, dataset);
    ui->tbl_Overview->setRowCount(dataset.size());
    logic::transaction buffer;
    QListIterator<logic::transaction> dataIterator(dataset);
    QTableWidgetItem *qTableWidgetItem;
    int i = 0;
    while(dataIterator.hasNext())
        {
            buffer = dataIterator.next();

            qTableWidgetItem = new QTableWidgetItem(buffer.getReason());
            qTableWidgetItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            ui->tbl_Overview->setItem(i, 0, qTableWidgetItem);

            qTableWidgetItem = new QTableWidgetItem(buffer.getComment());
            qTableWidgetItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            ui->tbl_Overview->setItem(i, 1, qTableWidgetItem);

            qTableWidgetItem = new QTableWidgetItem(QDate::fromString( buffer.getDate(),"yyyy-MM-dd").toString());
            qTableWidgetItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            ui->tbl_Overview->setItem(i, 2, qTableWidgetItem);

            qTableWidgetItem = new QTableWidgetItem(buffer.getCategory());
            qTableWidgetItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            ui->tbl_Overview->setItem(i, 3, qTableWidgetItem);

            qTableWidgetItem = new QTableWidgetItem(buffer.getPayment_Method());
            qTableWidgetItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            ui->tbl_Overview->setItem(i, 4, qTableWidgetItem);

            qTableWidgetItem = new QTableWidgetItem(QString::number(buffer.getValue()));
            qTableWidgetItem->setForeground(QBrush(buffer.getValue() > 0 ? QColor(0,255,0) : QColor(255,0,0)));
            qTableWidgetItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
            ui->tbl_Overview->setItem(i, 5, qTableWidgetItem);

            i++;
    }
}

void GUI::MainWindow::refreshui()
{
    QStringList list;
    household->retrieveCats(categorysset);
    QListIterator<logic::category> dataIterator(categorysset);
    list.clear();
    list.append("<none>");
    logic::category buffer;
    while(dataIterator.hasNext())
    {
        buffer = dataIterator.next();
        list.append(buffer.getCatName());
    }
    ui->cmb_Cat->addItems(list);

}

void GUI::MainWindow::on_btn_filter_clicked()
{
    filter();
}

int GUI::MainWindow::selected()
{
    QList<QTableWidgetSelectionRange> selected = ui->tbl_Overview->selectedRanges();

        if(selected.count())
        {
            int i = selected.first().topRow();

            return i;
        }
        GUI::gui_error::show("No Selection", "Please Select a Transaction");
        return -1;
}

void GUI::MainWindow::on_btn_addTrans_clicked()
{
    GUI::gui_addTransaction gui_addTransaction(categorysset,household, this);
    if(gui_addTransaction.exec() == QDialog::Accepted){
        filter();
    }
}

void GUI::MainWindow::on_btn_delete_clicked()
{
    int i = selected();


    //std::cerr << dataset.at(i).getReason().toStdString();

    if (i != -1){
        GUI::gui_addTransaction gui_addTransaction(dataset.at(i),categorysset, household, this);
        if(gui_addTransaction.exec() == QDialog::Accepted){
            filter();
        }
    }

    //std::cerr << i;
}
