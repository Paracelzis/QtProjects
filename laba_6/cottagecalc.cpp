#include "cottagecalc.h"

cottagecalc::cottagecalc(QObject *parent)
    : QObject{parent}
{

}

int cottagecalc::getCost(Estate *value)
{
    return value->getAge() + value->getArea() + value->getMonths() + value->getResidents();
}
