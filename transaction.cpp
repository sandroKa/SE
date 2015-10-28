#include "transaction.h"


QString logic::transaction::getDate_to() const
{
    return Date_to;
}

void logic::transaction::setDate_to(const QString &value)
{
    Date_to = value;
}

QString logic::transaction::getDate_from() const
{
    return Date_from;
}

void logic::transaction::setDate_from(const QString &value)
{
    Date_from = value;
}

int logic::transaction::getIndex() const
{
    return Index;
}

void logic::transaction::setIndex(int value)
{
    Index = value;
}

logic::transaction::transaction()
{
    
}

int logic::transaction::getTransID() const
{
    return TransID;
}

void logic::transaction::setTransID(int value)
{
    TransID = value;
}

int logic::transaction::getUserID() const
{
    return UserID;
}

void logic::transaction::setUserID(int value)
{
    UserID = value;
}

QString logic::transaction::getPayment_Method() const
{
    return Payment_Method;
}

void logic::transaction::setPayment_Method(const QString &value)
{
    Payment_Method = value;
}

QString logic::transaction::getReason() const
{
    return Reason;
}

void logic::transaction::setReason(const QString &value)
{
    Reason = value;
}

int logic::transaction::getValue() const
{
    return Value;
}

void logic::transaction::setValue(int value)
{
    Value = value;
}

QString logic::transaction::getCategory() const
{
    return Category;
}

void logic::transaction::setCategory(const QString &value)
{
    Category = value;
}

QString logic::transaction::getDate() const
{
    return Date;
}

void logic::transaction::setDate(const QString &value)
{
    Date = value;
}

QString logic::transaction::getComment() const
{
    return Comment;
}

void logic::transaction::setComment(const QString &value)
{
    Comment = value;
}
