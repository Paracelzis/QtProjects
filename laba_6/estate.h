#ifndef ESTATE_H
#define ESTATE_H

#include <QObject>

class Estate : public QObject
{
    Q_OBJECT
public:
    enum EstateType {
        ECONOM,
        LUXURIOUS,
        TOWN_HOUSE,
        COTTAGE
    };
    Estate(const int age, const int area, const int residents,
           const int months, const EstateType type, const QString owner); // Задание 1
    explicit Estate(QObject *parent = nullptr);
    EstateType getType() const; // Задание 1
    int getAge() const; // Задание 1
    int getArea() const; // Задание 1
    int getResidents() const; // Задание 1
    int getMonths() const; // Задание 1
    QString getOwner() const; // Задание 1
private:
    int age;
    int area;
    int residents;
    int months;
    EstateType type;
    QString owner;
};
#endif // ESTATE_H
