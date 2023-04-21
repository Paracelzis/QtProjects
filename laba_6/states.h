#ifndef STATES_H
#define STATES_H

#include <QObject>
#include <estate.h>

class States : public QObject
{
    Q_OBJECT
public:
    explicit States(QObject *parent = nullptr);
    ~States();
    void undo(); // Задание 2
    bool hasStates(); // Задание 2
    Estate *getActualData(); // Задание 2
    void add(Estate *value); // Задание 2
    int getSize();
signals:
    void notifyObservers();
private:
    QList<Estate *> array;
    Estate *actualData;

};

#endif
