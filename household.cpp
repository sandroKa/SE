#include "household.h"
#include "data.h"
#include "iostream"


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
