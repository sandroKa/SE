#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "household.h"
#include <QtWidgets/QMainWindow>

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

    private:
        Ui::MainWindow *ui;
        logic::Household *household;
    };
}
#endif // MAINWINDOW_H
