#ifndef LUXURIOUSAPARTMENTCALC_H
#define LUXURIOUSAPARTMENTCALC_H

#include <QObject>
#include <estate.h>

class luxuriousapartmentcalc : public QObject
{
    Q_OBJECT
public:
    explicit luxuriousapartmentcalc(QObject *parent = nullptr);
    static int getCost(Estate *value); //Задание 3

signals:

};

#endif // LUXURIOUSAPARTMENTCALC_H
