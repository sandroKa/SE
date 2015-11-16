#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "household.h"
#include "transaction.h"
#include "category.h"
#include <QtWidgets/QMainWindow>
#include <QList>

namespace Ui {
class MainWindow;
}

namespace GUI
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();

        int start(QApplication *);
        void filter();
        void refreshui();

    private slots:

        void slotFilter();

        int selected();
        void on_btn_addTrans_clicked();

        void on_btn_delete_clicked();

    private:
        Ui::MainWindow *ui;
        logic::Household *household;
        QLineEdit *rows[7];
        QList<logic::transaction> dataset;
        QList<logic::category> categorysset;
    };
}
#endif // MAINWINDOW_H
