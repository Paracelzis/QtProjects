#ifndef ESTATE_H
#define ESTATE_H
#include <QObject>

class Estate : public QObject
{
    Q_OBJECT
public:
    enum EstateType
    {
        ECONOM,
        LUXURIOUS,
        TOWN_HOUSE,
        COTTAGE
    };
    explicit Estate(QObject *parent = nullptr);
    EstateType getType() const;

private:
    int age;
    int area;
    int residents;
    int months;
    EstateType type;
    QString owner;
};

Estate::Estate(QString _age, QString _area, QString _residents, QString _months, QString _type, QString _owner)

{
    age = _age.toInt();
    area = _area.toInt();
    residents = _residents.toInt();
    months = _months.toInt();
    type = _type.;
    QString owner;

}
#endif // ESTATE_H
