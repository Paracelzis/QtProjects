#include "apartmentcalc.h"

apartmentcalc::apartmentcalc(QObject *parent)
    : QObject{parent}
{
}

int apartmentcalc::getCost(Estate *value)
{
    return value->getAge();
}
