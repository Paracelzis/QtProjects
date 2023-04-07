#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
 QWidget(parent),
 ui(new Ui::Widget),
 info(this)
{
 ui->setupUi(this);
 ui->btnUndo->setEnabled(false);
 // регистрация слушателя
 connect(&info, SIGNAL(notifyObservers()), this, SLOT(update()));
 connect(ui->btnCalc, SIGNAL(pressed()), this, SLOT(btnCalcPressed()));
 connect(ui->btnUndo, SIGNAL(pressed()), this, SLOT(btnUndoPressed()));
}

Widget::~Widget()
{
 delete ui;
}

// public slots
void Widget::update()
{
 auto value = info.getActualData();
 if(value != nullptr){
 fillForm(value);
 }
 // update btnUndo state
 ui->btnUndo->setEnabled(info.hasStates());
 // setting value to NULL
 value = nullptr;
}

// private slots
void Widget::btnCalcPressed()
{
    Estate *estate = new Estate(ui->age->text().toInt(),
                                ui->area->text().toInt(),
                                ui->residents->text().toInt(),
                                (ui->period->currentIndex() + 1) * 6,
                                (Estate::EstateType)ui->estateType->currentIndex(),
                                ui->owner->text());
    info.add(estate);
    ui->btnUndo->setEnabled(true);
    showCost(estate);
}

void Widget::btnUndoPressed()
{
    if (info.getSize() > 1)
    {
        info.undo();
    }
}
// private
Estate *Widget::processForm()
{
    return new Estate();
}

Widget::fillForm(Estate *value)
{
    ui->age->setText(QString::number(info.getActualData()->getAge()));
    ui->area->setText(QString::number(info.getActualData()->getArea()));
    ui->residents->setText(QString::number(info.getActualData()->getResidents()));
    ui->owner->setText(info.getActualData()->getOwner());
    ui->period->setCurrentIndex((info.getActualData()->getMonths() / 6) - 1);
    switch (info.getActualData()->getType())
    {
        case Estate::ECONOM:
        {
            ui->estateType->setCurrentIndex(0);
            break;
        }
        case Estate::LUXURIOUS:
        {
            ui->estateType->setCurrentIndex(1);
            break;
        }
        case Estate::TOWN_HOUSE:
        {
            ui->estateType->setCurrentIndex(2);
            break;
        }
        case Estate::COTTAGE:
        {
            ui->estateType->setCurrentIndex(3);
            break;
        }
    }
    ui->cost->setText(QString::number(CalculationFacade::getCost(info.getActualData())));
}

Widget::showCost(Estate *value)
{
    ui->cost->setText(QString::number(CalculationFacade::getCost(value)));
}


























//#include "widget.h"
//#include "./ui_widget.h"
//#include "estate.h"
//#include "states.h"
//#include "calculationfacade.h"

//Widget::Widget(QWidget *parent)
//    : QWidget(parent)
//    , ui(new Ui::Widget)
//{
//    ui->setupUi(this);
//}

//Widget::~Widget()
//{
//    delete ui;
//}


//void Widget::on_btnCalc_clicked()
//{
//    Estate *estate = new Estate(ui->age->text().toInt(),
//                                ui->area->text().toInt(),
//                                ui->residents->text().toInt(),
//                                (ui->period->currentIndex() + 1) * 6,
//                                (Estate::EstateType)ui->estateType->currentIndex(),
//                                ui->owner->text());
//    states.add(estate);
//    ui->cost->setText(QString::number(CalculationFacade::getCost(estate)));
//}


//void Widget::on_btnUndo_clicked()
//{
//    if (states.getSize() > 1)
//    {
//        states.undo();
//        ui->age->setText(QString::number(states.getActualData()->getAge()));
//        ui->area->setText(QString::number(states.getActualData()->getArea()));
//        ui->residents->setText(QString::number(states.getActualData()->getResidents()));
//        ui->owner->setText(states.getActualData()->getOwner());
//        ui->period->setCurrentIndex((states.getActualData()->getMonths() / 6) - 1);
//        switch (states.getActualData()->getType())
//        {
//            case Estate::ECONOM:
//            {
//                ui->estateType->setCurrentIndex(0);
//                break;
//            }
//            case Estate::LUXURIOUS:
//            {
//                ui->estateType->setCurrentIndex(1);
//                break;
//            }
//            case Estate::TOWN_HOUSE:
//            {
//                ui->estateType->setCurrentIndex(2);
//                break;
//            }
//            case Estate::COTTAGE:
//            {
//                ui->estateType->setCurrentIndex(3);
//                break;
//            }
//        }
//        ui->cost->setText(QString::number(CalculationFacade::getCost(states.getActualData())));
//    }
//}

