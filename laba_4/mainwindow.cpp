#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    validator(QRegularExpression("^[0-9]+$"))

{
    ui->setupUi(this);

    ui->quantity->setValidator(&validator);


    connect(ui->resultButton, &QPushButton::clicked,this,&MainWindow::on_PushButton_Clicked);
    connect(ui->quantity, &QLineEdit::textChanged,this,&MainWindow::on_TextChange);

    connect(ui->little, &QRadioButton::windowIconTextChanged,this,&MainWindow::on_TextChange);
    connect(ui->medium, &QRadioButton::windowIconTextChanged,this,&MainWindow::on_TextChange);
    connect(ui->large, &QRadioButton::windowIconTextChanged,this,&MainWindow::on_TextChange);
    connect(ui->glossy, &QRadioButton::windowIconTextChanged,this,&MainWindow::on_TextChange);
    connect(ui->matte, &QRadioButton::windowIconTextChanged,this,&MainWindow::on_TextChange);

}

void MainWindow::on_PushButton_Clicked()
{
    QLocale comma(QLocale::Russian);
    double quantity, total;

    quantity = ui->quantity->text().toInt();

    if (ui->little->isChecked() && ui->glossy->isChecked())
    {
        total = quantity * 16;
    }
    if (ui->little->isChecked() && ui->matte->isChecked())
    {
        total = quantity * 14;
    }

    if (ui->medium->isChecked() && ui->glossy->isChecked())
    {
        total = quantity * 20;
    }
    if (ui->medium->isChecked() && ui->matte->isChecked())
    {
        total = quantity * 18;
    }

    if (ui->large->isChecked() && ui->glossy->isChecked())
    {
        total = quantity * 25;
    }
    if (ui->large->isChecked() && ui->matte->isChecked())
    {
        total = quantity * 22;
    }


    QString str;
    str.setNum(total,'g',15);
    str += " руб.\n";
    ui->total->setText(str);
}

void MainWindow::on_TextChange(QString str)
{
    ui->total->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}


