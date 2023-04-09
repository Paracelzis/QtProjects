// Листинг файла estate.h
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
           const int months, const EstateType type, const QString owner);
    explicit Estate(QObject *parent = nullptr);
    EstateType getType() const;
    int getAge() const;
    int getArea() const;
    int getResidents() const;
    int getMonths() const;
    QString getOwner() const;
private:
    int age;
    int area;
    int residents;
    int months;
    EstateType type;
    QString owner;
};
#endif // ESTATE_H
