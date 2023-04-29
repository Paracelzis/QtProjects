#include "clientsWindow.h"
#include "ui_clientsWindow.h"
#include "ui_addintreedialog.h"

clientsWindow::clientsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientsWindow)
{
    ui->setupUi(this);
    Root = nullptr;
    addDialog = new addInTreeDialog();

    ui->clientsTableWidget->QTableView::setColumnHidden(0, 1);
    ui->clientsTableWidget->QTableView::setColumnHidden(1, 1);

    connect(addDialog, &addInTreeDialog::readyToAdd, this, &clientsWindow::addClient);
    connect(addDialog, &addInTreeDialog::readyToEdit, this, &clientsWindow::editClient);

    connect(ui->searchEdit, &QLineEdit::textChanged, this, &clientsWindow::on_searchEdit_textChanged);
}

clientsWindow::~clientsWindow()
{
    delete ui;
}

void clientsWindow::on_menuExitButton_clicked()
{
    this->close();
    emit menuWindow();
}

void clientsWindow::on_addButton_clicked()
{
    ui->searchEdit->clear();
    QPushButton* adder = (QPushButton*) sender();
    addDialog->sender = adder;
    addDialog->exec();
}

void clientsWindow::on_editButton_clicked()
{
    try {
        ui->searchEdit->clear();
        if (ui->clientsTableWidget->currentRow() < 0)
            throw myException("Не выбрана строка для редактирования");
        auto what = ui->clientsTableWidget->item(ui->clientsTableWidget->currentRow(), 2);
        long long key = what->text().remove(4, 1).toLongLong();
        clientsTree* tmp = Root->findKey(Root, key);
        client = tmp->getClient(tmp);
        QPushButton* pressed = (QPushButton*) sender();
        addDialog->sender = pressed;
        addDialog->ui->passportNumEdit->setText(client->getpassportNumber());
        addDialog->ui->placeAndDateEdit->setText(client->getPlaceAndDatePassport());
        addDialog->ui->nameEdit->setText(client->getName());
        addDialog->ui->adressEdit->setText(client->getadress());
        addDialog->ui->birthDateEdit->setText(QString::number(client->getyearBirth()));
        addDialog->exec();
    }
    catch (myException &err)
    {
        QMessageBox msg;
        msg.setWindowTitle("Ошибка!");
        msg.setFixedSize(500,400);
        msg.setText(err.what());
        msg.exec();
        return;
    }
}

void clientsWindow::on_deleteButton_clicked(){
    try{
        ui->searchEdit->clear();
        if (ui->clientsTableWidget->currentRow() < 0)
            throw myException("Не выбрана строка для удаления");
        auto what = ui->clientsTableWidget->item(ui->clientsTableWidget->currentRow(), 2);
        long long key = what->text().remove(4, 1).toLongLong();
        Root = Root->remove(Root, key);
        ui->clientsTableWidget->clearContents();
        ui->clientsTableWidget->setRowCount(0);
        tableReload(Root, 0);
        ui->clientsTableWidget->sortByColumn(1, Qt::AscendingOrder);
        ui->clientsTableWidget->sortByColumn(0, Qt::AscendingOrder);
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

void clientsWindow::on_clearButton_clicked(){
    ui->searchEdit->clear();
    Root->clearTree(Root);
    Root = NULL;
    ui->clientsTableWidget->clearContents();
    ui->clientsTableWidget->setRowCount(0);
}

void clientsWindow::addClient(){
    try {
        auto value = processForm();
        clientsTree* tmp = Root->findKey(Root, value->getpassportNumber().remove(4, 1).toLongLong());
        if (tmp != NULL)
            throw myException("Номер паспорта должен быть уникальным.");
        Root = Root->insert(Root, value);
        addDialog->close();
        //qDebug() << Root->getKey(Root);
        ui->clientsTableWidget->clearContents();
        ui->clientsTableWidget->setRowCount(0);
        tableReload(Root, 0);
        ui->clientsTableWidget->sortByColumn(1, Qt::AscendingOrder);
        ui->clientsTableWidget->sortByColumn(0, Qt::AscendingOrder);
    }
    catch(myException& error)
    {
        QMessageBox msg;
        msg.setWindowTitle("Ошибка!");
        msg.setFixedSize(500,400);
        msg.setText(error.what());
        msg.exec();
        return;
    }
}

void clientsWindow::editClient()
{
    auto what = ui->clientsTableWidget->item(ui->clientsTableWidget->currentRow(), 2);
    long long key = what->text().remove(4, 1).toLongLong();
    Root = Root->remove(Root, key);
    addClient();
}


clientsObj* clientsWindow::processForm(){
    return new clientsObj(addDialog->ui->passportNumEdit->text(), addDialog->ui->placeAndDateEdit->text(),
                            addDialog->ui->nameEdit->text(), addDialog->ui->birthDateEdit->text().toInt(),
                            addDialog->ui->adressEdit->text());
}

void clientsWindow::tableReload(clientsTree* Root, int count){
    if (!Root) return;
    this->client = Root->getClient(Root);
    ui->clientsTableWidget->insertRow(count);
    this->series = Root->getClient(Root)->getpassportNumber().remove(4, 7);
    this->number = Root->getClient(Root)->getpassportNumber().remove(0, 6);

    ui->clientsTableWidget->setItem(count, 0, new QTableWidgetItem(series));
    ui->clientsTableWidget->setItem(count, 1, new QTableWidgetItem(number));
    ui->clientsTableWidget->setItem(count, 2, new QTableWidgetItem(client->getpassportNumber()));
    ui->clientsTableWidget->setItem(count, 3, new QTableWidgetItem(client->getPlaceAndDatePassport()));
    ui->clientsTableWidget->setItem(count, 4, new QTableWidgetItem(client->getName()));
    ui->clientsTableWidget->setItem(count, 5, new QTableWidgetItem(QString::number(client->getyearBirth())));
    ui->clientsTableWidget->setItem(count, 6, new QTableWidgetItem(client->getadress()));

    tableReload(Root->getRight(Root), count + 1);
    tableReload(Root->getLeft(Root), count + 1);
}



void clientsWindow::on_searchEdit_textChanged(const QString& arg1) {

    QString searchText = arg1;
    int columnIndex = ui->searchComboBox->currentIndex() + 2;

    for (int i = 0; i < ui->clientsTableWidget->rowCount(); i++)
    {
        ui->clientsTableWidget->setRowHidden(i, true);
    }

    // Ищем строки, удовлетворяющие условию поиска
    for (int i = 0; i < ui->clientsTableWidget->rowCount(); i++) {
        bool match = false;
        QTableWidgetItem* item = ui->clientsTableWidget->item(i, columnIndex);
        if (item) {
            QString cellText = item->text();
            int j = 0;
            while (j <= cellText.length() - searchText.length()) {
                int k = 0;
                while (k < searchText.length() && searchText[k] == cellText[j + k]) {
                    k++;
                }
                if (k == searchText.length()) {
                    match = true;
                    break;
                }
                j++;
            }
            if (j == cellText.length() - searchText.length() + 1 && !match) {
                match = searchText.isEmpty(); // Если текст пустой, то считаем, что совпадение есть
            }
        }
        ui->clientsTableWidget->setRowHidden(i, !match);
    }
}


