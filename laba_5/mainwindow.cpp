#include "mainwindow.h"
#include "ui_mainwindow.h"

QString current_path;
QString data_tmp;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    validator(QRegularExpression("^[1-9]?[0-9]+$")),
    validator2(QRegularExpression("^[-]?[0-9]*[.,]?[0-9]+$"))

{
    ui->setupUi(this);

    ui->lineEdit_index->setValidator(&validator);
    ui->lineEdit_data->setValidator(&validator2);

    connect(ui->take_from_file, &QPushButton::clicked,this,&MainWindow::take_from_file_pushButton_clicked);
    connect(ui->show_to_index, &QPushButton::clicked, this, &MainWindow::show_to_index_pushButton_clicked);
    connect(ui->delete_to_index, &QPushButton::clicked,this,&MainWindow::delete_to_index_pushButton_clicked);
    connect(ui->delete_to_data, &QPushButton::clicked,this,&MainWindow::delete_to_data_pushButton_clicked);
    connect(ui->AddItem, &QPushButton::clicked,this,&MainWindow::AddItem_pushButton_clicked);
    connect(ui->summa, &QPushButton::clicked,this,&MainWindow::summa_pushButton_clicked);
    connect(ui->sum_chet, &QPushButton::clicked,this,&MainWindow::summa_pushButton_clicked);
    connect(ui->clear_collection, &QPushButton::clicked,this,&MainWindow::clear_collection_pushButton_clicked);
    connect(ui->summa_task2, &QPushButton::clicked,this,&MainWindow::summa_task2_pushButton_clicked);
    connect(ui->save_in_file, &QPushButton::clicked,this,&MainWindow::save_in_file_pushButton_clicked);
    connect(ui->file_name, SIGNAL(currentIndexChanged(int)), this, SLOT(on_file_name_currentIndexChanged));
    connect(ui->lineEdit_index, &QLineEdit::textChanged, this, &MainWindow::text_changed);
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

void MainWindow::AddItem_pushButton_clicked()
{
    if(ui->lineEdit_data->text() == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!","Напишите значение нового элемента.");
        messageBox.setFixedSize(500,200);
        return;
    }

    QVector <double> vec;

    QLocale comma(QLocale::Russian);

    double index;

    if (ui->lineEdit_data->text().contains(","))
    {
        index = comma.toInt(ui->lineEdit_index->text());
    }
    else
    {
        index = ui->lineEdit_data->text().toInt();
    }

    data_tmp += QString::number(index);

    QStringList list = data_tmp.split("\n");

    foreach (const QString &str, list)
    {
        vec << str.toDouble();
    }

    ui->initial_collection->clear();
    ui->converted_collection->clear();

    for (int i = 0; i < vec.size(); i++)
    {
        qDebug() << "kekeke" << vec[i];
    }

    QString data;

    qDebug() << data;

    for (int i = 0; i < vec.size(); i++)
    {
        if (QString::number(vec[i]) != "")
        {
            data +=  (QString::number(vec[i]) + "\n");
        }
    }

    data_tmp = data;

    fill(data);
}

void MainWindow::summa_pushButton_clicked()
{
    if(ui->initial_collection->count() == 0 or ui->initial_collection->item(0)->text() == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!","Исходная коллекция пуста.");
        messageBox.setFixedSize(500,200);
        return;
    }

    QPushButton* result = (QPushButton*) sender();

    double sum = 0;

    if (result->text() == "Сумма элементов")
    {
        for (int i = 0; i < ui->initial_collection->count(); i++)
        {
            QString item = ui->initial_collection->item(i)->text();

            sum += item.toDouble();
        }
        ui->lineEdit_sum->setText(QString::number(sum));
    }

    if (result->text() == "Сумма четных элементов")
    {
        for (int i = 0; i < ui->initial_collection->count(); i++)
        {
            QString item = ui->initial_collection->item(i)->text();
            double k = item.toDouble();

            int a = static_cast<int>(k);

            if (a % 2 == 0)
            {
                sum += item.toDouble();
            }
        }
        ui->lineEdit_sum->setText(QString::number(sum));
    }
}

void MainWindow::show_to_index_pushButton_clicked()
{
    if (ui->lineEdit_index->text() == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!","Введите индекс.");
        messageBox.setFixedSize(500,200);
        return;
    }

    if(ui->initial_collection->count() == 0 or ui->initial_collection->item(0)->text() == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!","Исходная коллекция пуста.");
        messageBox.setFixedSize(500,200);
        return;
    }

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
            QMessageBox messageBox;
            messageBox.critical(0,"Ошибка!","Индекс больше размера коллекции.");
            messageBox.setFixedSize(500,200);
        }
    }
}

void MainWindow::delete_to_index_pushButton_clicked()
{
    if (ui->lineEdit_index->text() != "")
    {
        delete_combo(0);
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!","Введите индекс.");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::delete_to_data_pushButton_clicked()
{
    if (ui->lineEdit_data->text() != "")
    {
        delete_combo(1);
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!","Введите значение элемента.");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::delete_combo(int funk) //удаление по индексу - 0, удаление по значению - 1
{
    if(ui->initial_collection->count() == 0 or ui->initial_collection->item(0)->text() == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!","Исходная коллекция пуста.");
        messageBox.setFixedSize(500,200);
        return;
    }

    QVector <double> vec;

    QStringList list = data_tmp.split("\n");

    int index = 0;

    foreach (const QString &str, list)
    {
        vec << str.toDouble();
    }

    if (funk == 0)
    {
        QString text_index = ui->lineEdit_index->text();
        index = text_index.toInt();
    }
    else
    {
        for (int i = 0; i < vec.size() - 1; i++)
        {
            if (QString::number(vec[i]) == ui->lineEdit_data->text())
            {
                index = i + 1;
                break;
            }
            else
            {
                index = 0;
            }
        }
        if (index == 0)
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Ошибка!","Элемент не найден.");
            messageBox.setFixedSize(500,200);
            return;
        }
    }

    qDebug() << index;

    if (index <= vec.size() and index > 0)
    {
        ui->initial_collection->clear();
        ui->converted_collection->clear();

        vec.erase(vec.begin() + (index - 1));

        QString data;

        for (int i = 0; i < vec.size() - 1; i++)
        {
            if (QString::number(vec[i]) != "")
            {
                data +=  (QString::number(vec[i]) + "\n");
            }
        }

//        for (int i = 0; i < vec.size(); i++)
//        {
//            qDebug() << "kekeke" << vec[i];
//        }

        qDebug() << data;

        data_tmp = data;

        fill(data);
    }
    else
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!","Индекс больше размера коллекции.");
        messageBox.setFixedSize(500,200);
    }
}

void MainWindow::clear_collection_pushButton_clicked()
{
    ui->initial_collection->clear();
    ui->converted_collection->clear();

    data_tmp = "";

    ui->initial_collection->addItem("");
    ui->converted_collection->addItem("");

    ui->file_name->setPlaceholderText("                        Выберите файл");

    ui->lineEdit_data->clear();
    ui->lineEdit_index->clear();
    ui->lineEdit_sum->clear();
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
        if (vec[i] == 0)
        {
            tmp.push_back(vec[i]);
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

    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (QString::number(vec[i]) != "")
        {
            data2 +=  (QString::number(vec[i]) + "\n");
        }
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
        //qDebug() << "Element vec:" << str;
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

void MainWindow::summa_task2_pushButton_clicked()
{
    if(ui->initial_collection->count() == 0 or ui->initial_collection->item(0)->text() == "")
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Ошибка!","Исходная коллекция пуста.");
        messageBox.setFixedSize(500,200);
        return;
    }

    QVector <double> vec;

    QStringList list = data_tmp.split("\n");
    foreach (const QString &str, list)
    {
        vec << str.toDouble();
    }

    int k = 0;
    double sum = 0;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] < 0)
        {
            k = i;
            break;
        }
    }
    for (int i = k + 1; i < vec.size(); i++)
    {
        if (vec[i] < 0)
        {
            break;
        }
        else
        {
            sum += vec[i];
        }
    }

    ui->lineEdit_sum->setText(QString::number(sum));
}

void MainWindow::save_in_file_pushButton_clicked()
{
    QFile file(QFileDialog::getSaveFileName(this,"Сохранить файл", "C:/Users/HOME-PC/Documents/QtProjects/QtProjects/laba_5","TXT File(*.txt)"));

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Can't open file";
    }
    else
    {
        QStringList list = data_tmp.split("\n");

        QTextStream out(&file);

        out << data_tmp;

        file.close();
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


