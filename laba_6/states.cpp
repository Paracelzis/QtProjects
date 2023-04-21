#include "states.h"


States::States(QObject *parent) : QObject(parent)
{
    actualData = nullptr;
}


States::~States()
{
    if(actualData)
    {
    delete actualData;
    actualData = nullptr;
    }
    qDeleteAll(array);
    array.clear();
}

// Задание 2
void States::add(Estate *value)
{
    array.append(value);
}

// Задание 2
bool States::hasStates()
{
    return !(States::array.empty());
}

// Задание 2
Estate *States::getActualData()
{
    return actualData;
}

// Задание 2
void States::undo()
{
    if (hasStates())
    {
        array.pop_back();
        actualData = array.last();
        emit notifyObservers();
    }
    else
        actualData = nullptr;
}


int States::getSize()
{
    return array.size();
}
