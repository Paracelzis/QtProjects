#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    validator(QRegularExpression("^[0-9]+$"))

{
    ui->setupUi(this);

    ui->quantity->setValidator(&validator);

    connect(ui->quantity, &QLineEdit::textChanged,this,&MainWindow::on_TextChange);

    connect(ui->little, &QRadioButton::clicked,this,&MainWindow::on_RadioButton_Clicked);
    connect(ui->medium, &QRadioButton::clicked,this,&MainWindow::on_RadioButton_Clicked);
    connect(ui->large, &QRadioButton::clicked,this,&MainWindow::on_RadioButton_Clicked);
    connect(ui->glossy, &QRadioButton::clicked,this,&MainWindow::on_RadioButton_Clicked);
    connect(ui->matte, &QRadioButton::clicked,this,&MainWindow::on_RadioButton_Clicked);
}

void MainWindow::on_RadioButton_Clicked()
{
    double quantity, total;

    quantity = ui->quantity->text().toDouble();

    if (ui->little->isChecked() == false and ui->medium->isChecked() == false and ui->large->isChecked() == false)
    {
        return;
    }
    if (ui->glossy->isChecked() == false and ui->matte->isChecked() == false)
    {
        return;
    }

    if (ui->little->isChecked() && ui->glossy->isChecked())
    {
        total = 16;
    }
    if (ui->little->isChecked() && ui->matte->isChecked())
    {
        total = 14;
    }

    if (ui->medium->isChecked() && ui->glossy->isChecked())
    {
        total = 20;
    }
    if (ui->medium->isChecked() && ui->matte->isChecked())
    {
        total = 18;
    }

    if (ui->large->isChecked() && ui->glossy->isChecked())
    {
        total = 25;
    }
    if (ui->large->isChecked() && ui->matte->isChecked())
    {
        total = 22;
    }

    total *= quantity;


    QString str;
    str.setNum(total,'g',15);
    str += " руб.\n";
    ui->total->setText(str);
}

void MainWindow::on_TextChange()
{
    ui->total->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}


