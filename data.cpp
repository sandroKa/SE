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

void Data::Data::retrieveTrans(const logic::transaction &trans, QList<logic::transaction> &dataset)
{
    dataset.clear();
    QString Date_from = trans.getDate_from(), Date_to = trans.getDate_to();
    int index = trans.getIndex();
    QString sql = "SELECT Reason, Comment, Date, CategoryID, PaymentMethod, Value FROM TransactionDB WHERE UserID = :id";
    sql += Date_from.isEmpty() ? "" : " AND Date(Date) Between Date(:Date_from)";
    sql += Date_to.isEmpty() ? "" : " AND Date(:Date_to)";
    sql += index == 0 ? "" : " limit :index";
    sql += ";";


    if(query.prepare(sql))
        {
            query.bindValue(":id", trans.getUserID());
            if(!Date_from.isEmpty())
                query.bindValue(":Date_from", Date_from);
            if(!Date_to.isEmpty())
                query.bindValue(":Date_to", Date_to);
            if(index > 0)
                query.bindValue(":index", index);
            if(query.exec())
                    {
                        logic::transaction buffer;

                        while(query.next())
                        {
                            buffer.setReason(query.value(0).toString());
                            buffer.setComment(query.value(1).toString());
                            buffer.setDate(query.value(2).toString());
                            buffer.setCategory(query.value(3).toString());
                            buffer.setPayment_Method(query.value(4).toString());
                            buffer.setValue(query.value(5).toInt());
                            dataset.append(buffer);
                        }                        
                        return;
                    }
         }
    cerr << query.lastError().text().toStdString() << endl;
}



Data::Data::~Data()
{

}

void Data::Data::createDatabase()
{

}

