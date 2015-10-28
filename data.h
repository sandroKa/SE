#ifndef DATA_H
#define DATA_H

#include <QtSql>
#include "idata.h"

namespace Data
{
    class Data : public IData
    {
    public:
        Data();
        virtual void reset(bool);
        virtual bool isLocked(const QString&);
        virtual int newMember(const QString&);
        virtual void deleteMember(int);
        virtual QString retrieveMemberPassword(const QString&);
        virtual QString retrieveMemberPassword(int);
        virtual int retrieveMemberID(const QString&);
        virtual void setMemberPassword(const QString&, int);
        virtual void retrieveMemberList(QList<int>&);
        virtual int updateLogins(int, bool);
        virtual void lock(int);
        virtual void retrieveTrans(const logic::transaction&, QList<logic::transaction>&);
        virtual void retrieveCats(QList<logic::category>&);

        virtual ~Data();
    private:
                //QSqlDatabase db;
                QSqlQuery query;

                void createDatabase();
    };
}
#endif // DATA_H
