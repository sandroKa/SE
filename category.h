#ifndef CATEGORY_H
#define CATEGORY_H
#include <QString>

namespace logic
{
    class category
    {
        private:
            int CatID;
            QString CatName;
            QString CatDesc;
        public:
            category();
            int getCatID() const;
            void setCatID(int value);
            QString getCatName() const;
            void setCatName(const QString &value);
            QString getCatDesc() const;
            void setCatDesc(const QString &value);
    };
}


#endif // CATEGORY_H
