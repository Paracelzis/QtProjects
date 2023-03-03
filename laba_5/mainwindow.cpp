#include "mainwindow.h"
#include "ui_mainwindow.h"

QString current_path;
QString data_tmp;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->take_from_file, &QPushButton::clicked,this,&MainWindow::take_from_file_pushButton_clicked);
    connect(ui->show_to_index, &QPushButton::clicked, this, &MainWindow::show_to_index_pushButton_clicked);
    connect(ui->file_name, SIGNAL(currentIndexChanged(int)), this, SLOT(on_file_name_currentIndexChanged));
    connect(ui->lineEdit_index, &QLineEdit::textChanged, this, &MainWindow::text_changed);
    connect(ui->delete_to_index, &QPushButton::clicked,this,&MainWindow::delete_to_index_pushButton_clicked);

}


void MainWindow::take_from_file_pushButton_clicked()
{
    QFile file(QFileDialog::getOpenFileName(this,"Выбрать файл", "C:/Users/HOME-PC/Documents/QtProjects/QtProjects/laba_5","TXT File(*.txt)"));

    QFileInfo fileinfo(file);
    current_path = fileinfo.path();

    QDir path(current_path);
    QString current_item = fileinfo.fileName();

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

        ui->file_name->setCurrentText(current_item);
        QString data;

        data = file.readAll();
        data_tmp = data;

        fill(data);
    }
}

void MainWindow::show_to_index_pushButton_clicked()
{
    if (ui->lineEdit_index->text() != "")
    {
        QString element = ui->lineEdit_index->text();
        int index = element.toInt();

        QVector <double> vec;

        QStringList list = data_tmp.split("\n");
        foreach (const QString &str, list)
        {
            vec << str.toDouble();
        }

        if (index <= vec.size() and index > 0)
        {
            double k = vec[index - 1];

            ui->lineEdit_data->setText(QString::number(k));
        }
        else
        {
            ui->lineEdit_data->setText("Ошибка! Индекс больше/меньше размера коллекции.");
        }
    }
}

void MainWindow::delete_to_index_pushButton_clicked()
{

    if (ui->lineEdit_index->text() != "")
    {
        QString text_index = ui->lineEdit_index->text();
        int index = text_index.toInt();

        QVector <double> vec;

        QStringList list = data_tmp.split("\n");
        foreach (const QString &str, list)
        {
            vec << str.toDouble();
        }

        if (index <= vec.size() and index > 0)
        {

            vec.erase(std::remove(vec.begin(),vec.end(), vec.at(index - 1)),vec.end());
            vec.resize(vec.size() - 1);

            ui->initial_collection->clear();
            ui->converted_collection->clear();

            QString data;

            for (int i = 0; i < vec.size(); ++i)
            {
                data +=  (QString::number(vec[i]) + "\n");
            }
            data_tmp = data;

            fill(data);
        }
        else
        {
            ui->lineEdit_data->setText("Ошибка! Индекс больше/меньше размера коллекции.");
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
            data_tmp = data;
            //qDebug() << QString(data);

            fill(data);
        }
    }

}

void MainWindow::text_changed()
{
    ui->lineEdit_data->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}


