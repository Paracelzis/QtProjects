#include "apartmentcalc.h"

double apartmentCalc::getCost(estate *value){
    return value->getAge() * 1000;
}
