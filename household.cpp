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

bool logic::Household::loginUser(const QString &mail, const QString &password)
{
    if(password.isEmpty())
    {
        return false;
    }

    if(password.compare(data->retrieveMemberPassword(mail)) == 0)
        {
            this->id = data->retrieveMemberID(mail);
            return true;
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
