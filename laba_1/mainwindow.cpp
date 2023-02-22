#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      validator(QRegularExpression("^[-]?[0-9]*[.,]?[0-9]+$"))

{
    QLocale comma(QLocale::Russian);
    ui->setupUi(this);

    ui->lineEdit->setValidator(&validator);
    ui->lineEdit_2->setValidator(&validator);

    this->setWindowTitle ("Калькулятор");
          
          
          
          
          
    connect(ui->pushButton, &QPushButton::clicked,this,&MainWindow::on_PushButton_Clicked);
    connect(ui->pushButton_2, &QPushButton::clicked,this,&MainWindow::on_PushButton_Clicked);
    connect(ui->pushButton_3, &QPushButton::clicked,this,&MainWindow::on_PushButton_Clicked);
    connect(ui->pushButton_4, &QPushButton::clicked,this,&MainWindow::on_PushButton_Clicked);
    connect(ui->lineEdit, &QLineEdit::textChanged,this,&MainWindow::on_TextChange);
    connect(ui->lineEdit_2, &QLineEdit::textChanged,this,&MainWindow::on_TextChange);
}

void MainWindow::on_PushButton_Clicked()
{
    QLocale comma(QLocale::Russian);
    QPushButton* result = (QPushButton*) sender();
    double te , te2, r;

    if (ui->lineEdit->text().contains(","))
    {
        te = comma.toDouble(ui->lineEdit->text());
    }
    else
    {
        te = ui->lineEdit->text().toDouble();
    }
    if (ui->lineEdit_2->text().contains(","))
    {
        te2 = comma.toDouble(ui->lineEdit_2->text());
    }
    else
    {
        te2 = ui->lineEdit_2->text().toDouble();
    }

    if (result->text() == "+")
    {
        r =  te + te2;
    }
    else if (result->text() == "-")
    {
        r =  te - te2;
    }
    else if (result->text() == "*")
    {
        r =  te * te2;
    }
    else if (result->text() == "/")
    {
        if (te2 == 0)
        {
            ui->lineEdit_3->setText("Ошибка! Деление на 0.");
            return;
        }
        r =  te / te2;
    }

    QString str;
    str.setNum(r);
    ui->lineEdit_3->setText(str);
}

void MainWindow::on_TextChange(QString str)
{
    ui->lineEdit_3->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

