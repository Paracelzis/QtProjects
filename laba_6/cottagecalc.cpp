#include "cottagecalc.h"

cottagecalc::cottagecalc(QObject *parent)
    : QObject{parent}
{
}

//Задание 3
int cottagecalc::getCost(Estate *value)
{
    return value->getAge() + value->getArea() + value->getMonths() + value->getResidents();
}
