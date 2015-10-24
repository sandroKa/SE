#ifndef HOUSEHOLD_H
#define HOUSEHOLD_H

#include "data.h"

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
            bool loginUser(const QString&, const QString&);
            int newUser(const QString&);
            bool deleteUser(int);
            bool setNewPassword(const QString&, int);

    };
}

#endif // HOUSEHOLD_H
