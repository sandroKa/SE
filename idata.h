#ifndef IDATA
#define IDATA

#include <QString>
#include <QList>
namespace Data
{
    class IData
    {
        public:
        virtual ~IData(){}
        virtual void reset(bool) = 0;
        virtual int newMember(const QString&) = 0;
        virtual void deleteMember(int) = 0;
        virtual QString retrieveMemberPassword(const QString&) = 0;
        virtual QString retrieveMemberPassword(int) = 0;
        virtual int retrieveMemberID(const QString&) = 0;
        virtual void setMemberPassword(const QString&, int) = 0;
        virtual void retrieveMemberList(QList<int>&) = 0;

    };
}


#endif // IDATA

