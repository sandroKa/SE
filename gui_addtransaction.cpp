#include "gui_addtransaction.h"
#include "gui_error.h"
#include "ui_gui_addtransaction.h"
#include <iostream>
#include <limits>
#include <QMessageBox>


GUI::gui_addTransaction::gui_addTransaction(QList<logic::category> &categorysset, logic::Household *household, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gui_addTransaction),
    household(household),
    categorysset(categorysset),
    change(false)
{
    ui->setupUi(this);
    ui->date->setDate(QDate::currentDate());
    ui->btn_Delete->setVisible(false);
    start(categorysset);

}

GUI::gui_addTransaction::gui_addTransaction(logic::transaction trans, QList<logic::category> &cat, logic::Household *household, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gui_addTransaction),
    household(household),
    categorysset(cat),
    preTrans(trans),
    change(true)
{
    ui->setupUi(this);
    start(categorysset);
    ui->btn_Delete->setEnabled(true);
    ui->btn_Delete->setStyleSheet("color: red");
    ui->txt_Comment->setText(trans.getComment());
    ui->txt_Payment->setText(trans.getPayment_Method());
    ui->txt_Reason->setText(trans.getReason());
    ui->txt_Value->setText(QString::number(trans.getValue()));
    ui->cmb_Cat->setCurrentIndex(trans.getCategoryID()-1); /* TO DO: REWORK IT CAN FAIL due to Database changes */
}

GUI::gui_addTransaction::~gui_addTransaction()
{
    delete ui;
}

void GUI::gui_addTransaction::on_buttonBox_accepted()
{
    QIntValidator v(INT_MIN, INT_MAX, this);
    QString Value = ui->txt_Value->text();
    int asd = 0;
    //std::cerr <<  v.validate(test, asd);
    if (ui->txt_Reason->text().isEmpty() || ui->txt_Value->text().isEmpty() || v.validate(Value, asd) != 2 || Value == "0")
    {
        GUI::gui_error::show("Error", "Include a Reason or a correct vaule");
    }
    else
    {
        logic::transaction trans;
        trans.setComment(ui->txt_Comment->toPlainText());
        trans.setUserID(household->getId());
        trans.setReason(ui->txt_Reason->text());
        trans.setDate(ui->date->date().toString("yyyy-MM-dd"));
        trans.setPayment_Method(ui->txt_Payment->text());
        trans.setValue(Value.toInt());
        trans.setTransID(preTrans.getTransID());
        std::cerr << preTrans.getTransID();
        QListIterator<logic::category> dataIterator(categorysset);
        logic::category buffer;
        while(dataIterator.hasNext())
        {
            buffer = dataIterator.next();
            if(buffer.getCatName() == ui->cmb_Cat->currentText())
                trans.setCategoryID(buffer.getCatID());
        }
        if(!change){
            if(!household->insertTrans(trans)){
                GUI::gui_error::show("Error", "Transaction couldn´t be added \n maybe there is already a similar one");
                return;
            }
        }
        else
        {
            if(!household->updateTrans(trans)){
                GUI::gui_error::show("Error", "Transaction couldn´t be added \n maybe there is already a similar one");
                return;
            }
        }
        accept();
    }
}

void GUI::gui_addTransaction::start(QList<logic::category> &categorysset)
{
    ui->date->setDate(QDate::currentDate());
    QStringList list;
    QListIterator<logic::category> dataIterator(categorysset);
    list.clear();
    logic::category buffer;
    while(dataIterator.hasNext())
    {
        buffer = dataIterator.next();
        list.append(buffer.getCatName());
    }
    ui->cmb_Cat->addItems(list);
}

void GUI::gui_addTransaction::on_btn_Delete_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Transaction", "Do you really want to delete \n this Transaction?",
                                    QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        household->deleteTrans(preTrans.getTransID());
        accept();
    }
}
