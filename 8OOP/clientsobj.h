#ifndef CLIENTSOBJ_H
#define CLIENTSOBJ_H

#include <QObject>
#include <myexception.h>

class clientsObj : public QObject
{
    Q_OBJECT
public:
    explicit clientsObj(QObject *parent = nullptr);
    clientsObj(const QString passportNumber, const QString PlaceAndDatePassport,
               const QString name, const int yearBirth, const QString adress);
    QString getpassportNumber();
    QString getPlaceAndDatePassport();
    QString getName();
    QString getadress();
    int getyearBirth();
private:
    QString passportNumber, PlaceAndDatePassport, Name, adress;
    int yearBirth;
};

#endif // CLIENTSOBJ_H
