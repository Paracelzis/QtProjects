#include "infosimobj.h"

infosimObj::infosimObj(QObject *parent)
    : QObject{parent}
{
    this->simNumber = "dummy";
    this->rate = "-1";
    this->year = -1;
    this->isThere = "dummy";
}

infosimObj::infosimObj(const QString simNumber, const QString rate, const int year, const bool isThere)
{
    if (simNumber.size() < 10 || rate == "")
        throw myException("Поля формы заполнены некорректно.");
    if (year < 1900 || year > 2100)
        throw myException("Поле года выпуска заполнено некорректно.");
    this->simNumber = simNumber;
    this->rate = rate;
    this->year = year;
    this->isThere = isThere;
}

QString infosimObj::getsimNumber(){
    return this->simNumber;
}

QString infosimObj::getRate(){
    return this->rate;
}

int infosimObj::getYear(){
    return this->year;
}

bool infosimObj::getIsThere(){
    return this->isThere;
}
