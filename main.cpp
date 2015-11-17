#include "mainwindow.h"
#include "login.h"
#include <data.h>
#include <idata.h>
#include <iostream>

using namespace std;


#include <QApplication>
#include <QStandardPaths>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    cerr << "Start" << endl;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/Trax/Documents/Studium/SE/Household/HouseholdDB"); //BirkDB
    //db.setDatabaseName("C:\\Users\\crina\\Documents\\GitHub\\Haushaltsfuehrung\\SE\\SE\\HouseholdDB"); //CrinaDB
    if (!db.open())
        {
            cerr << "Fehler beim oeffnen der Datenbank!" << endl;
            return 1;
        }
     /*To debug the Path for x-Platform*/
     //QString test = QFileInfo( QCoreApplication::applicationFilePath() ).absolutePath();
     //cerr << test.toStdString();
     GUI::MainWindow mainwindow;
     return mainwindow.start(&a);
}
