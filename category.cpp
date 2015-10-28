#include "category.h"




logic::category::category()
{

}

int logic::category::getCatID() const
{
    return CatID;
}

void logic::category::setCatID(int value)
{
    CatID = value;
}

QString logic::category::getCatName() const
{
    return CatName;
}

void logic::category::setCatName(const QString &value)
{
    CatName = value;
}

QString logic::category::getCatDesc() const
{
    return CatDesc;
}

void logic::category::setCatDesc(const QString &value)
{
    CatDesc = value;
}
