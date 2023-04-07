#include "townhousecalc.h"

townhousecalc::townhousecalc(QObject *parent)
    : QObject{parent}
{

}

int townhousecalc::getCost(Estate *value)
{
    return value->getAge() + value->getArea() + value->getResidents();
}
