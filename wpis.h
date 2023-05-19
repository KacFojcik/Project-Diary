#ifndef WPIS_H
#define WPIS_H
#include <QString>
#include <QDateTime>


class Wpis
{
public:
    Wpis(QString t, QDateTime d, QString n);
    QString getTresc(){return tresc;}
    QDateTime getData() {return data;}
    QString getNastroj() {return nastroj;}

    bool operator==(const Wpis& w) const;
    bool operator!=(const Wpis& w) const;
    bool operator>(const Wpis& w);
private:
    QString tresc;
    QDateTime data;
    QString nastroj;

};

#endif // WPIS_H
