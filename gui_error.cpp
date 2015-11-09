#include "gui_error.h"
#include <QMessageBox>

GUI::gui_error::gui_error()
{

}


void GUI::gui_error::show(QString title, QString text)
{
    QMessageBox qMessageBox;
    qMessageBox.setWindowTitle(title);
    qMessageBox.setText(text);
    qMessageBox.setWindowFlags(Qt::WindowStaysOnTopHint);
    qMessageBox.exec();
}
