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
    timerId = 0;

}

GUI::Login::~Login()
{
    delete ui;
}


/*Timer for the Infobox motion*/
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
        timerId = 0;
        status = true;
    }
}


void GUI::Login::on_btn_OK_clicked()
{
    if(timerId > 0){
        killTimer(timerId);
        ui->Info_Frame->setFixedHeight(frameheight = 0);
    }
    QString mail = ui->txt_user->text();
    ui->txt_Info_Frame->setStyleSheet("QLabel { color : red; }");
    if(mail == "" || ui->txt_password->text() == "")
    {
        ui->txt_Info_Frame->setText("User/Password field is empty");
        timerId = startTimer(10);
        return;
    }
    // Hashing Password to Sha256
    QString password = ui->txt_password->text();
    QByteArray hash = QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Sha256);
    hash = hash.toBase64();
    int loginval = household->loginUser(mail, hash);
    if (loginval == 1)
    {
        household->setId(household->retrieveUserID(mail));
        accept();
    }
    else if (loginval == -2){
        timerId = startTimer(10);
        ui->txt_Info_Frame->setText("Account is Locked");
        ui->txt_password->setText("");
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
