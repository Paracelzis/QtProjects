#ifndef APARTMENTCALC_H
#define APARTMENTCALC_H

#include <QObject>
#include <estate.h>

class apartmentcalc : public QObject
{
    Q_OBJECT
public:
    explicit apartmentcalc(QObject *parent = nullptr);
    static int getCost(Estate *value); //Задание 3

signals:

};

#endif // APARTMENTCALC_H
