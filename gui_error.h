#ifndef GUI_ERROR_H
#define GUI_ERROR_H

#include <QString>
#include <QWidget>

namespace GUI
{
    class gui_error
    {
    public:
        gui_error();
        static void show(QString title, QString text);
    };
}
#endif // GUI_ERROR_H
