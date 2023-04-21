#ifndef TOWNHOUSECALC_H
#define TOWNHOUSECALC_H

#include <QObject>
#include <estate.h>

class townhousecalc : public QObject
{
    Q_OBJECT
public:
    explicit townhousecalc(QObject *parent = nullptr);
    static int getCost(Estate *value); //Задание 3

signals:

};

#endif // TOWNHOUSECALC_H
