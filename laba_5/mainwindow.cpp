#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    connect(ui->take_from_file, &QPushButton::clicked,this,&MainWindow::on_pushButton_clicked);
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->take_from_file->text() == "Взять коллекцию из файла")
    {
        QFile file("C:/Users/HOME-PC/Documents/QtProjects/QtProjects/laba_5/initial_data.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Can't open file";
        }
        else
        {
            QString data;
            data = file.readAll();
            qDebug() << QString(data);

            ui->initial_collection->addItems(data.split("\n"));

            QVector<double> vec;
            QStringList list = data.split("\n");

            foreach (const QString &str, list)
            {
                vec << str.toDouble();
                qDebug() << "Element:" << str;
            }

//            foreach (const double &str, vec)
//               qDebug() << "Element:" << str;



        }

    }



}



MainWindow::~MainWindow()
{
    delete ui;
}

