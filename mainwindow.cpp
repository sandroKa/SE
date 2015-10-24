#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

GUI::MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    household = new logic::Household();
}

GUI::MainWindow::~MainWindow()
{
    delete ui;
}

int GUI::MainWindow::start(QApplication *qApplication)
{
    GUI::Login Login(household, this);
    int exec = Login.exec();
    if(exec == QDialog::Accepted)
    {
        show();
        return qApplication->exec();
    }
    else
    {
        return exec;
    }
}
