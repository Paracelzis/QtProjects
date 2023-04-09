#include "luxuriousapartmentcalc.h"

luxuriousapartmentcalc::luxuriousapartmentcalc(QObject *parent)
    : QObject{parent}
{

}


int luxuriousapartmentcalc::getCost(Estate *value)
{
    return value->getAge() + value->getResidents();
}
