#include "calculationfacade.h"

CalculationFacade::CalculationFacade(QObject *parent) : QObject(parent)
{
}

int CalculationFacade::getCost(Estate *value)
{
    int cost;
    switch (value->getType())
    {
        case Estate::EstateType::ECONOM:
        {
            cost = apartmentcalc::getCost(value);
            break;
        }
        case Estate::EstateType::LUXURIOUS:
        {
            cost = luxuriousapartmentcalc::getCost(value);
            break;
        }
        case Estate::EstateType::TOWN_HOUSE:
        {
            cost = townhousecalc::getCost(value);
            break;
        }
        case Estate::EstateType::COTTAGE:
        {
            cost = cottagecalc::getCost(value);
            break;
        }
        default:
        {
            cost = -1;
            break;
        }
    }
    return cost;
}
