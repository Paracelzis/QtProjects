#include "infosimWindow.h"
#include "ui_addinhashdialog.h"
#include "ui_infosimWindow.h"

infosimWindow::infosimWindow(clientsTree *&Root, myHashTable *&hashTable, QWidget *parent):
    QWidget(parent),
    ui(new Ui::infosimWindow),
    hashTable(hashTable),
    Root(Root)
{
    ui->setupUi(this);
    addDialog = new addinhashdialog();

    connect(ui->searchEdit, &QLineEdit::textChanged, this, &infosimWindow::on_searchEdit_textChanged);

    connect(addDialog, &addinhashdialog::readytoAdd, this, &infosimWindow::addSIM);
    connect(addDialog, &addinhashdialog::readytoEdit, this, &infosimWindow::editSIM);

}

infosimWindow::~infosimWindow()
{
    delete ui;
}

void infosimWindow::on_menuExitButton_clicked()
{
    this->close();
    emit menuWindow();
}

void infosimWindow::on_searchEdit_textChanged()
{
    QString line;
    if (ui->searchEdit->text().length() == 0)
    {
        ui->infoSimTableWidget->clearContents();
        ui->infoSimTableWidget->setRowCount(0);
        tableReload();
        ui->infoSimTableWidget->sortByColumn(0, Qt::AscendingOrder);
        return;
    }
    for (int row = 0; row < ui->infoSimTableWidget->rowCount(); row++)
    {
        QTableWidgetItem *item = ui->infoSimTableWidget->item(row, 0);
        infosimObj* tmp = hashTable->search(item->text());
        if (!tmp) continue;
        ui->searchComboBox->currentIndex() == 0 ? line = tmp->getsimNumber() : line = tmp->getRate();
        QVector<int> occurrences = searchEngine::directSearch(line, ui->searchEdit->text());
        if (!occurrences.empty())
            ui->infoSimTableWidget->showRow(row);
        else
            ui->infoSimTableWidget->hideRow(row);
    }
}

infosimObj* infosimWindow::processForm()
{
    return new infosimObj(addDialog->ui->simNumberEdit->text(),
                          addDialog->ui->rateEdit->text(),
                          addDialog->ui->yearEdit->text().toInt(),
                          addDialog->ui->isThereComboBox->currentIndex());
}

void infosimWindow::on_addButton_clicked()
{
    ui->searchEdit->clear();
    QPushButton* pressed = (QPushButton* )sender();
    addDialog->sender = pressed;
    addDialog->exec();
}

void infosimWindow::addSIM()
{
    try {
        auto value = processForm();
        infosimObj* tmp = hashTable->search(value->getsimNumber());
        if (tmp != NULL) throw myException("Номер SIM-карты должен быть уникальным");
        hashTable->insertNode(value);
        addDialog->close();
        //qDebug() << Root->getKey(Root);
        ui->infoSimTableWidget->clearContents();
        ui->infoSimTableWidget->setRowCount(0);
        tableReload();
        ui->infoSimTableWidget->sortByColumn(0, Qt::AscendingOrder);
    }
    catch(myException& error){
        QMessageBox msg;
        msg.setWindowTitle("Ошибка!");
        msg.setFixedSize(500,400);
        msg.setText(error.what());
        msg.exec();
        return;
    }
}

void infosimWindow::tableReload()
{
    if (hashTable->isEmpty()) return;
    int count = 0;
    for (int i = 0; i < hashTable->capacity; i++)
    {
        if (hashTable->arr[i] != NULL && hashTable->arr[i]->getYear() != -1)
        {
            ui->infoSimTableWidget->insertRow(count);
            ui->infoSimTableWidget->setItem(count, 0, new QTableWidgetItem(hashTable->arr[i]->getsimNumber()));
            ui->infoSimTableWidget->setItem(count, 1, new QTableWidgetItem(hashTable->arr[i]->getRate()));
            ui->infoSimTableWidget->setItem(count, 2, new QTableWidgetItem(QString::number(hashTable->arr[i]->getYear())));
            ui->infoSimTableWidget->setItem(count, 3, new QTableWidgetItem(QString::number(hashTable->arr[i]->getIsThere())));
        }
    }
}

void infosimWindow::on_deleteButton_clicked(){
    try {
        ui->searchEdit->clear();
        if (ui->infoSimTableWidget->currentRow() < 0)
            throw myException("Не выбрана строка для удаления");
        auto what = ui->infoSimTableWidget->item(ui->infoSimTableWidget->currentRow(), 0);
        hashTable->deleteNode(what->text());
        ui->infoSimTableWidget->clearContents();
        ui->infoSimTableWidget->setRowCount(0);
        tableReload();
        ui->infoSimTableWidget->sortByColumn(0, Qt::AscendingOrder);
    }
    catch (myException &err){
        QMessageBox msg;
        msg.setWindowTitle("Ошибка!");
        msg.setFixedSize(500,400);
        msg.setText(err.what());
        msg.exec();
        return;
    }
}

void infosimWindow::on_editButton_clicked()
{
    try {
        ui->searchEdit->clear();
        if (ui->infoSimTableWidget->currentRow() < 0)
            throw myException("Не выбрана строка для редактирования");
        auto what = ui->infoSimTableWidget->item(ui->infoSimTableWidget->currentRow(), 0);
        infosimObj* tmp = hashTable->search(what->text());
        if (tmp == NULL)
            throw myException("Элемент не найден.");
        QPushButton* pressed = (QPushButton* )sender();
        addDialog->sender = pressed;
        addDialog->ui->simNumberEdit->setText(tmp->getsimNumber());
        addDialog->ui->rateEdit->setText(tmp->getRate());
        addDialog->ui->yearEdit->setText(QString::number(tmp->getYear()));
        addDialog->ui->isThereComboBox->setCurrentText(QString::number(tmp->getIsThere()));
        addDialog->exec();
    }
    catch (myException &err){
        QMessageBox msg;
        msg.setWindowTitle("Ошибка!");
        msg.setFixedSize(500,400);
        msg.setText(err.what());
        msg.exec();
        return;
    }
}

void infosimWindow::editSIM()
{
    try {
        auto what = ui->infoSimTableWidget->item(ui->infoSimTableWidget->currentRow(), 0);
        QString number = addDialog->ui->simNumberEdit->text();
        infosimObj* tmp = hashTable->search(number);
        if (tmp != NULL && tmp->getsimNumber() != what->text())
            throw myException("Номер SIM-карты должен быть уникален.");
        hashTable->deleteNode(what->text());
        addSIM();
    }
    catch (myException &ex){
        QMessageBox msg;
        msg.setWindowTitle("Ошибка!");
        msg.setFixedSize(500,400);
        msg.setText(ex.what());
        msg.exec();
        return;
    }
}

void infosimWindow::on_clearButton_clicked()
{
    ui->searchEdit->clear();
    if (hashTable->isEmpty()) return;
    hashTable->clear();
    ui->infoSimTableWidget->clearContents();
    ui->infoSimTableWidget->setRowCount(0);
}

