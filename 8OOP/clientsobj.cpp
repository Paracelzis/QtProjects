#include "clientsobj.h"

clientsObj::clientsObj(QObject *parent)
    : QObject{parent}
{

}

clientsObj::clientsObj(const QString passportNumber, const QString PlaceAndDatePassport, const QString Name, const int yearBirth, const QString adress)
{
    if (passportNumber.size() < 10 || PlaceAndDatePassport == "" || Name == "" || adress == "")
        throw myException("Поля формы заполнены некорректно.");

    if (yearBirth < 1900 || yearBirth > 2100)
        throw myException("Поле года рождения заполнено некорректно.");
    this->passportNumber = passportNumber;
    this->PlaceAndDatePassport = PlaceAndDatePassport;
    this->Name = Name;
    this->yearBirth = yearBirth;
    this->adress = adress;
}

QString clientsObj::getpassportNumber()
{
    return this->passportNumber;
}

QString clientsObj::getPlaceAndDatePassport()
{
    return this->PlaceAndDatePassport;
}

QString clientsObj::getName()
{
    return this->Name;
}

QString clientsObj::getadress()
{
    return this->adress;
}

int clientsObj::getyearBirth()
{
    return this->yearBirth;
}
