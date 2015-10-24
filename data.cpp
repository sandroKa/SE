#include "data.h"
#include <iostream>

using namespace std;


Data::Data::Data()
{

}

void Data::Data::reset(bool)
{

}

int Data::Data::newMember(const QString &)
{

}

void Data::Data::deleteMember(int)
{

}

QString Data::Data::Data::retrieveMemberPassword(const QString &mail)
{
    if(!query.prepare("SELECT Password FROM UserDB "
                          "WHERE UserDB.E_Mail = :mail;"))
        {
            cerr << query.lastError().text().toStdString() << endl;
        }
        else
        {
            query.bindValue(":mail", mail);
            if(!query.exec())
            {
                cerr << query.lastError().text().toStdString() << endl;
            }
            else
            {
                query.next();
                return query.value(0).toString();
            }

        }
    return NULL;
}

QString Data::Data::retrieveMemberPassword(int id)
{
    if(!query.prepare("SELECT Password FROM UserDB "
                          "WHERE UserDB.ID = :id;"))
        {
            cerr << query.lastError().text().toStdString() << endl;
        }
        else
        {
            query.bindValue(":id", id);
            if(!query.exec())
            {
                cerr << query.lastError().text().toStdString() << endl;
            }
            else
            {
                query.next();
                return query.value(0).toString();
            }

        }
    return NULL;
}

int Data::Data::retrieveMemberID(const QString &mail)
{
    if(!query.prepare("SELECT ID FROM UserDB "
                          "WHERE UserDB.E_Mail = :mail;"))
        {
            cerr << query.lastQuery().toStdString() << endl;
            cerr << query.lastError().text().toStdString() << endl;
        }
        else
        {
            query.bindValue(":mail", mail);
            if(!query.exec())
            {
                cerr << query.lastQuery().toStdString() << endl;
                cerr << query.lastError().text().toStdString() << endl;
            }
            else
            {
                query.next();
                return query.value(0).toInt();
            }

        }
    return -1;
}

void Data::Data::setMemberPassword(const QString &, int)
{

}

void Data::Data::retrieveMemberList(QList<int> &)
{

}

Data::Data::~Data()
{

}

void Data::Data::createDatabase()
{

}

