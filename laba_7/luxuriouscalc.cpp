#include "luxuriouscalc.h"

double luxuriousCalc::getCost(estate *value){
    return (value->getAge() + value->getResidents()) * 1000;
}
