#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QString>

namespace logic
{
    class transaction
    {
    private:
        int TransID;
        int UserID;
        QString Payment_Method;
        QString Reason;
        int Value;
        QString Category;
        QString Date;
        QString Date_from;
        QString Date_to;
        QString Comment;
        int Index;

    public:
        transaction();

        int getTransID() const;
        void setTransID(int value);
        int getUserID() const;
        void setUserID(int value);
        QString getPayment_Method() const;
        void setPayment_Method(const QString &value);
        QString getReason() const;
        void setReason(const QString &value);
        int getValue() const;
        void setValue(int value);
        QString getCategory() const;
        void setCategory(const QString &value);
        QString getDate() const;
        void setDate(const QString &value);
        QString getComment() const;
        void setComment(const QString &value);
        QString getDate_to() const;
        void setDate_to(const QString &value);
        QString getDate_from() const;
        void setDate_from(const QString &value);
        int getIndex() const;
        void setIndex(int value);
    };
}
#endif // TRANSACTION_H
