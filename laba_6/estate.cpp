#include "estate.h"
#include <widget.h>

Estate::Estate(QObject *parent)
    : QObject(parent)
{
    age = 25;
    area = 170;
    residents = 56;
    months = 6;
    owner = "Иванов";
    type = Estate::ECONOM;
}

// Задание 1
Estate::Estate(const int age, const int area, const int residents,
        const int months, const EstateType type, const QString owner)
{
    this->age = age;
    this->area = area;
    this->residents = residents;
    this->months = months;
    this->owner = owner;
    this->type = type;
}

// Задание 1
Estate::EstateType Estate::getType() const
{
    return this->type;
}

// Задание 1
int Estate::getAge() const
{
    return this->age;
}

// Задание 1
int Estate::getArea() const
{
    return this->area;
}

// Задание 1
int Estate::getResidents() const
{
    return this->residents;
}

// Задание 1
int Estate::getMonths() const
{
    return this->months;
}

// Задание 1
QString Estate::getOwner() const
{
    return this->owner;
}
