#ifndef ABSTRACTCALC_H
#define ABSTRACTCALC_H

#include <estate.h>

class abstractCalc
{
public:
    abstractCalc();
    virtual double getCost(estate* value) = 0;
    virtual ~abstractCalc() {}
};

#endif // ABSTRACTCALC_H
