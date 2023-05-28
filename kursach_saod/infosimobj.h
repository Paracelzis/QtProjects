#ifndef INFOSIMOBJ_H
#define INFOSIMOBJ_H

#include <QObject>
#include "myexception.h"

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

    bool isThere;
private:
    QString simNumber, rate;
    int year;
};


#endif // INFOSIMOBJ_H
