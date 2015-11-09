#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include "data.h"
#include "transaction.h"
#include "category.h"

namespace logic
{
    class Household
    {
        private:
            int id;

        public:
            Data::Data *data;


            static const int ADMIN_ID = 1;

            Household();
            ~Household();

            bool isAdmin() const;
            int loginUser(const QString&, const QString&);
            int newUser(const QString&);
            bool deleteUser(int);
            bool setNewPassword(const QString&, int);
            int retrieveUserID(const QString&);
            void retrieveTrans(const transaction&, QList<transaction>&dataset) const;
            bool insertTrans(const transaction&) const;
            bool updateTrans(const transaction&) const;
            bool deleteTrans(int) const;
            void retrieveCats(QList<category>&) const;
            int getId() const;
            void setId(int value);
    };
}

#endif // HOUSEHOLD_H
