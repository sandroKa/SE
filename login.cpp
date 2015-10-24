#include "login.h"
#include "ui_login.h"
#include "data.h"
#include "iostream"
#include <QtDebug>
#include <QApplication>
#include <QCryptographicHash>

GUI::Login::Login(logic::Household *household,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login),
    household(household)
{
    ui->setupUi(this);
    status = true;
    frameheight = 0;

}

GUI::Login::~Login()
{
    delete ui;
}



void GUI::Login::timerEvent(QTimerEvent *event)
{
    if(status && frameheight<40){
        ui->Info_Frame->setFixedHeight(frameheight++);
    }else if (status && frameheight == 40){
        killTimer(timerId);
        timerId = startTimer(10);
        status = false;
    }else if(!status && frameheight > 0){
        ui->Info_Frame->setFixedHeight(frameheight--);
    }else if(!status && frameheight == 0){
        killTimer(timerId);
        status = true;
    }
}


void GUI::Login::on_btn_OK_clicked()
{
    QString password = ui->txt_password->text();
    QByteArray hash = QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Sha256);
    hash = hash.toBase64();
    QString mail = ui->txt_user->text();
    if(mail == "")
    {
        std::cerr << "Empty Username";
    }
    else if (household->loginUser(mail, hash))
    {
        std::cerr << "test erfolgreich";
        accept();
    }
    else
    {
        timerId = startTimer(10);
        ui->txt_Info_Frame->setText("Failed to Login");
        ui->txt_password->setText("");
    }
}

void GUI::Login::on_btn_Cancel_clicked()
{
    qApp->quit();
}
