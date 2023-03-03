#include "mainwindow.h"
#include "ui_mainwindow.h"

QString current_path;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->take_from_file, &QPushButton::clicked,this,&MainWindow::on_pushButton_clicked);
    connect(ui->file_name, SIGNAL(currentIndexChanged(int)), this, SLOT(on_file_name_currentIndexChanged));

}


void MainWindow::on_pushButton_clicked()
{
    if (ui->take_from_file->text() == "Взять коллекцию из файла")
    {
        QFile file(QFileDialog::getOpenFileName(this,"Выбрать файл", "C:/Users/HOME-PC/Documents/QtProjects/QtProjects/laba_5","TXT File(*.txt)"));

        QFileInfo fileinfo(file);
        current_path = fileinfo.path();
        QDir path(current_path);

        QStringList nameFilter;
        nameFilter<<"*.txt";
        QStringList files = path.entryList(nameFilter, QDir::Files);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Can't open file";
        }
        else
        {
            ui->initial_collection->clear();
            ui->converted_collection->clear();
            ui->file_name->clear();

            ui->file_name->addItems(files);

            QString data;
            data = file.readAll();
            //qDebug() << QString(data);

            fill(data);
        }

    }
}

QString MainWindow::convert_collection(QVector<double>& vec)
{
    QVector<double> tmp;

    for (unsigned i = vec.size(); i-- > 0; )
    {
        if (vec[i] < 0)
        {
            tmp.push_front(vec[i]);
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] > 0)
        {
            tmp.push_back(vec[i]);
        }
    }

    vec = tmp;

    tmp.clear();
    tmp.shrink_to_fit();

    QString data2;

    for (int i = 0; i < vec.size(); ++i)
    {
        data2 +=  (QString::number(vec[i]) + "\n");
    }

    return data2;
}
void MainWindow::fill(QString data)
{
    ui->initial_collection->addItems(data.split("\n"));

    QVector<double> vec;
    QStringList list = data.split("\n");

    foreach (const QString &str, list)
    {
        vec << str.toDouble();
        qDebug() << "Element vec:" << str;
    }

    convert_collection(vec);

    ui->converted_collection->addItems(convert_collection(vec).split("\n"));
}

void MainWindow::on_file_name_currentIndexChanged()
{
    QString current_item = ui->file_name->currentText();

    QString current_file = current_path + "/"+ current_item;

    qDebug() << current_file;

    QFile file(current_file);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Can't open file";
    }
    else
    {
        if (ui->initial_collection->count())
        {
            ui->initial_collection->clear();
            ui->converted_collection->clear();

            QString data;
            data = file.readAll();
            //qDebug() << QString(data);

            fill(data);
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


