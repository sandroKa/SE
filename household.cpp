#include "household.h"
#include "data.h"
#include "iostream"

int logic::Household::getId() const
{
    return id;
}

void logic::Household::setId(int value)
{
    id = value;
}

logic::Household::Household() : data(new Data::Data)
{
    
}

logic::Household::~Household()
{
    delete data;
}

bool logic::Household::isAdmin() const
{
    return id == ADMIN_ID;
}

int logic::Household::loginUser(const QString &mail, const QString &password)
{
    int tempid = data->retrieveMemberID(mail);
    if(password.isEmpty())
    {
        return false;
    }
    if(data->isLocked(mail))
    {
        std::cerr << "locked";
        return -2;
    }
    if(password.compare(data->retrieveMemberPassword(mail)) == 0)
        {
            this->id = tempid;
            data->updateLogins(tempid, true);
            return true;
        }
    if(data->updateLogins(tempid, false) == -2)
    {
        data->lock(tempid);
        return -2;
    }
    return false;
}

int logic::Household::newUser(const QString &)
{

}

bool logic::Household::deleteUser(int)
{

}

bool logic::Household::setNewPassword(const QString &, int)
{

}

int logic::Household::retrieveUserID(const QString &mail)
{
       return data->retrieveMemberID(mail);
}

void logic::Household::retrieveTrans(const transaction &trans, QList<logic::transaction> &dataset) const
{
    data->retrieveTrans(trans, dataset);
}

bool logic::Household::insertTrans(const logic::transaction &trans) const
{
    return data->insertTrans(trans);
}

bool logic::Household::updateTrans(const logic::transaction &trans) const
{
    return data->updateTrans(trans);
}

bool logic::Household::deleteTrans(int TransID) const
{
    return data->deleteTrans(TransID);
}

void logic::Household::retrieveCats(QList<logic::category> &Cats) const
{
    data->retrieveCats(Cats);
}
