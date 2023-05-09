#ifndef INFOSIMOBJ_H
#define INFOSIMOBJ_H

#include <QObject>

class infosimObj: public QObject
{
    Q_OBJECT
public:
    explicit infosimObj(QObject *parent = nullptr);
    infosimObj(const QString simNumber, const QString rate, const int year, const bool isThere);
    QString getsimNumber();
    QString getRate();
    int getYear();
    bool getIsThere();
private:
    QString simNumber, rate;
    int year;
    bool isThere;
};


#endif // INFOSIMOBJ_H
