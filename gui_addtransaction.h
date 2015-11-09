#ifndef GUI_ADDTRANSACTION_H
#define GUI_ADDTRANSACTION_H
#include "household.h"
#include <QList>
#include <QDialog>

namespace Ui {
class gui_addTransaction;
}

namespace GUI
{
    class gui_addTransaction : public QDialog
    {
        Q_OBJECT

    public:
        explicit gui_addTransaction(QList<logic::category> &categorysset,logic::Household *,QWidget *parent = 0);
        explicit gui_addTransaction(logic::transaction trans, QList<logic::category> &cat, logic::Household *, QWidget *parent = 0);
        ~gui_addTransaction();

    private slots:
        void on_buttonBox_accepted();

        void on_btn_Delete_clicked();

    private:
        void start(QList<logic::category> &categorysset);
        Ui::gui_addTransaction *ui;
        logic::Household *household;
        QList<logic::category> &categorysset;
        logic::transaction preTrans;
        bool change;
    };
}
#endif // GUI_ADDTRANSACTION_H
