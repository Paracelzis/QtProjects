#include "widget.h"
#include "ui_widget.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    info(this)
{
    ui->setupUi(this);
    ui->btnUndo->setEnabled(false);
    connect(&info, SIGNAL(notifyObservers()), this, SLOT(update()));
    connect(ui->btnCalc, SIGNAL(pressed()), this, SLOT(btnCalcPressed()));
    connect(ui->btnUndo, SIGNAL(pressed()), this, SLOT(btnUndoPressed()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::update()
{
    auto value = info.getActualData();
    if(value != nullptr){
        fillForm(value);
    }
    ui->btnUndo->setEnabled(info.hasStates());
    value = nullptr;
}

void Widget::btnCalcPressed()
{
    try {
    if (ui->age->text().toInt() == 0 || ui->area->text().toInt() == 0
        || ui->owner->text() == "" || ui->residents->text().toInt() == 0){
        throw myException("Не все поля формы заполнены.");
    }
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
    catch (myException &ex) {
        QMessageBox err;
        err.setText(ex.what());
        err.setWindowTitle("Ошибка!");
        err.exec();
        return;
    }
}
void Widget::btnUndoPressed()
{
    if (info.getSize() > 1){
        info.undo();
    }
}

//Задание 4
Estate *Widget::processForm()
{
    return new Estate();
}

//Задание 4
void Widget::fillForm(Estate *value)
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

//Задание 4
void Widget::showCost(Estate *value)
{
    ui->cost->setText(QString::number(CalculationFacade::getCost(value)));
}
