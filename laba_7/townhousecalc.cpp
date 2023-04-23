#include "townhousecalc.h"

double townhouseCalc::getCost(estate *value){
    return (value->getAge() + value->getArea() + value->getResidents()) * 1000;
}
