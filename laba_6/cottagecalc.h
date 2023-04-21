#ifndef COTTAGECALC_H
#define COTTAGECALC_H

#include <QObject>
#include <estate.h>

class cottagecalc : public QObject
{
    Q_OBJECT
public:
    explicit cottagecalc(QObject *parent = nullptr);
    static int getCost(Estate *value); //Задание 3

signals:

};

#endif // COTTAGECALC_H
