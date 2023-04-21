#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <states.h>
#include <estate.h>
#include <calculationfacade.h>
#include <myexception.h>

namespace Ui
{
class Widget;
}
class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void update();
private slots:
    void btnCalcPressed();
    void btnUndoPressed();
private:
    Estate *processForm(); //Задание 4
    void fillForm(Estate *value); //Задание 4
    void showCost(Estate *value); //Задание 4
private:
    Ui::Widget *ui;
    States info;
};
#endif // WIDGET_H
