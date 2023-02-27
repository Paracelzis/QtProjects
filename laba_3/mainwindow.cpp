#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    validator(QRegularExpression("^[0-9]*[.,]?[0-9]+$"))

{
    ui->setupUi(this);

    ui->lenght_text->setValidator(&validator);
    ui->width_text->setValidator(&validator);

    connect(ui->result_Button, &QPushButton::clicked,this,&MainWindow::on_PushButton_Clicked);

    connect(ui->lenght_text, &QLineEdit::textChanged,this,&MainWindow::on_TextChange);
    connect(ui->width_text, &QLineEdit::textChanged,this,&MainWindow::on_TextChange);
    connect(ui->cost_text, &QLineEdit::textChanged,this,&MainWindow::on_TextChange);
    connect(ui->choice, &QComboBox::currentTextChanged,this,&MainWindow::on_TextChange);

}

void MainWindow::on_PushButton_Clicked()
{
    QLocale comma(QLocale::Russian);
    double width, length, cost, res;

    if (ui->width_text->text().contains(","))
    {
        width = comma.toDouble(ui->width_text->text());
    }
    else
    {
        width = ui->width_text->text().toDouble();
    }
    if (ui->lenght_text->text().contains(","))
    {
        length = comma.toDouble(ui->lenght_text->text());
    }
    else
    {
        length = ui->lenght_text->text().toDouble();
    }
    if (ui->cost_text->text().contains(","))
    {
        cost = comma.toDouble(ui->cost_text->text());
    }
    else
    {
        cost = ui->cost_text->text().toDouble();
    }

    res = width * length * cost;

    QString str;
    str.setNum(res,'g',15);
    str += " руб.\n";
    ui->result_label->setText("Итог: " + str);
}

void MainWindow::on_TextChange(QString str)
{
    ui->result_label->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

