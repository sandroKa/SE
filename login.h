#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "household.h"

namespace Ui {
class Login;
}
namespace GUI
{
    class Login : public QDialog
    {
        Q_OBJECT

    public:
        explicit Login(logic::Household *,QWidget *parent = 0);
        ~Login();

    private slots:


        void on_btn_OK_clicked();

        void on_btn_Cancel_clicked();

    private:
        Ui::Login *ui;
        logic::Household *household;
        int timerId;
        int frameheight;
        bool status;
    protected:
        void timerEvent(QTimerEvent *event);
    };
}

#endif // LOGIN_H
