#include "wpis.h"

Wpis::Wpis(QString t, QDateTime d, QString n)
{
    tresc = t;
    data = d;
    nastroj = n;
}

bool Wpis::operator==(const Wpis &w) const
{
        if(this->data != w.data)
            return false;
        else
            return true;
}

bool Wpis::operator!=(const Wpis &w) const
{
    return !(*this == w);
}


bool Wpis::operator>(const Wpis &w)
{
    return this->data > w.data;
}
