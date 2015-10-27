#include "data.h"
#include <iostream>

using namespace std;


Data::Data::Data()
{

}

void Data::Data::reset(bool)
{

}

bool Data::Data::isLocked(const QString &mail)
{
    if(!query.prepare("SELECT Locked FROM UserDB "
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
                return query.value(0).toInt();
            }

        }
    return false;
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

int Data::Data::updateLogins(int id, bool reset)
{
    int Login_Tries = 0;
    if (!reset)
    {
        if(!query.prepare("SELECT Login_Tries FROM UserDB "
                              "WHERE UserDB.ID = :id;"))
            {
                cerr << query.lastQuery().toStdString() << endl;
                cerr << query.lastError().text().toStdString() << endl;
            }
            else
            {
                query.bindValue(":id", id);
                if(!query.exec())
                {
                    cerr << query.lastQuery().toStdString() << endl;
                    cerr << query.lastError().text().toStdString() << endl;
                }
                else
                {
                    query.next();
                    Login_Tries = query.value(0).toInt();
                    if(Login_Tries == 2){
                        return -2;
                    }
                    Login_Tries++;
                }
            }
    }
    else
    {
        Login_Tries = 0;
    }
    cerr << Login_Tries;

    if(!query.prepare("UPDATE UserDB SET Login_Tries = :value "
                          "WHERE ID = :id;"))
        {
            cerr << query.lastError().text().toStdString() << endl;
        }
        else
        {
            query.bindValue(":value", Login_Tries);
            query.bindValue(":id", id);

            if(!query.exec())
            {
                cout << query.lastError().text().toStdString() << endl;
            }
        }
    return Login_Tries;
}

void Data::Data::lock(int id)
{
    if(!query.prepare("UPDATE UserDB SET Locked = 1 "
                          "WHERE ID = :id;"))
        {
            cerr << query.lastError().text().toStdString() << endl;
        }
        else
        {
            query.bindValue(":id", id);

            if(!query.exec())
            {
                cout << query.lastError().text().toStdString() << endl;
            }
        }
}

Data::Data::~Data()
{

}

void Data::Data::createDatabase()
{

}

