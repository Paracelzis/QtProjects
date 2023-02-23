#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    boxes = this->findChildren<QCheckBox*>();
    connect(ui->checkBox, &QCheckBox::clicked,this,&MainWindow::on_CheckBox_Clicked);
    connect(ui->checkBox_2, &QCheckBox::clicked,this,&MainWindow::on_CheckBox_Clicked);
    connect(ui->checkBox_3, &QCheckBox::clicked,this,&MainWindow::on_CheckBox_Clicked);
    connect(ui->checkBox_4, &QCheckBox::clicked,this,&MainWindow::on_CheckBox_Clicked);
    connect(ui->checkBox_5, &QCheckBox::clicked,this,&MainWindow::on_CheckBox_Clicked);
    connect(ui->checkBox_6, &QCheckBox::clicked,this,&MainWindow::on_CheckBox_Clicked);
}

void MainWindow::on_CheckBox_Clicked()
{
    double all = 1500000, complekt = 0;
    QString tmp = "Цена автомобиля - 1 500 000 руб.\n";


    if (ui->checkBox->isChecked())
    {
        all += 5362.50;
        complekt += 5362.50;
        tmp += "Цена шин - 5362.50 руб.\n";
    }

    if (ui->checkBox_2->isChecked())
    {
        all += 8562.99;
        complekt += 8562.99;
        tmp += "Цена дисков - 8562.99 руб.\n";
    }

    if (ui->checkBox_3->isChecked())
    {
        all += 23628.50;
        complekt += 23628.50;
        tmp += "Цена каско - 23628.50 руб.\n";
    }

    if (ui->checkBox_4->isChecked())
    {
        all += 19842.52;
        complekt += 19842.52;
        tmp += "Цена ОСАГО - 19842.52 руб.\n";
    }

    if (ui->checkBox_5->isChecked())
    {
        all += 16500;
        complekt += 16500;
        tmp += "Цена кондиционера - 5362.50 руб.\n";
    }

    if (ui->checkBox_6->isChecked())
    {
        all += 15562;
        complekt += 15562;
        tmp += "Цена сигнализации - 15562 руб.\n";
    }


    if (all == 0)
    {
        tmp += "Не выбрано ни одного комплектующего.\n";
    }

    if (prov() == 1)
    {
        all = (89458.5 * 0.9) + 1500000;
        tmp += "Вы выбрали все комплектующие, вам положена скидка 10%.\n";
    }

    QString str,str2;

    str.setNum(all,'g',15);
    str += " руб.\n";

    str2.setNum(complekt,'g',15);
    str2 += " руб.\n";

    ui->result->setText(tmp + "Цена комплектующих: " + str2 + "Итог: " + str);
}

bool MainWindow::prov()
{
    QCheckBox* tmp;
    auto it = boxes.begin();
    while (it != boxes.end())
    {
        tmp = *it;
        if (tmp->isChecked())
            ++it;
        else
            return 0;
    }
    return 1;
}



MainWindow::~MainWindow()
{
    delete ui;
}

