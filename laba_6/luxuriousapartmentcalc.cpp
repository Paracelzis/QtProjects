#include "luxuriousapartmentcalc.h"

luxuriousapartmentcalc::luxuriousapartmentcalc(QObject *parent)
    : QObject{parent}
{
}

//Задание 3
int luxuriousapartmentcalc::getCost(Estate *value)
{
    return value->getAge() + value->getResidents();
}
