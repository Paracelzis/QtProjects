#include "apartmentcalc.h"

apartmentcalc::apartmentcalc(QObject *parent)
    : QObject{parent}
{
}

//Задание 3
int apartmentcalc::getCost(Estate *value)
{
    return value->getAge();
}
