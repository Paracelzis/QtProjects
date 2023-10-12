#include "clientsWindow.h"
#include "ui_clientsWindow.h"
#include "ui_addintreedialog.h"

clientsWindow::clientsWindow(clientsTree*& Root, myHashTable*& hashTable, mylist*& List, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientsWindow),
    Root(Root),
    hashTable(hashTable),
    List(List)
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
    QPushButton* pressed = (QPushButton*) sender();
    addDialog->sender = pressed;
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
    catch (myException &err){
        QMessageBox msg;
        msg.setWindowTitle("Ошибка!");
        msg.setFixedSize(500,400);
        msg.setText(err.what());
        msg.exec();
        return;
    }
}

void clientsWindow::on_deleteButton_clicked()
{
    try {
        ui->searchEdit->clear();
        if (ui->clientsTableWidget->currentRow() < 0)
            throw myException("Не выбрана строка для удаления");
        auto what = ui->clientsTableWidget->item(ui->clientsTableWidget->currentRow(), 2);
        QString passport = what->text();
        long long key = what->text().remove(4, 1).toLongLong();
        auto appearence = List->searchElement(passport);
        if (appearence.size() != 0)
        {
            QMessageBox foundInMoves;
            foundInMoves.setWindowTitle("Внимание!");
            foundInMoves.setText("У этого пользователя есть SIM-карты. Удаление этого пользователя приведет к удалению записей о выдаче/возврате.");
            QAbstractButton* yesButton = foundInMoves.addButton(tr("Удалить"), QMessageBox::YesRole);
            QAbstractButton* noButton = foundInMoves.addButton(tr("Отмена"), QMessageBox::NoRole);
            foundInMoves.exec();
            if (foundInMoves.clickedButton() == yesButton){
                for (int i = 0; i < appearence.size(); i++){
                    List->remove(appearence[i]->getSimNumber());
                }
                emit toReloadTable();
            }
            else return;
        }

        Root = Root->remove(Root, key);
        ui->clientsTableWidget->clearContents();
        ui->clientsTableWidget->setRowCount(0);
        tableReload(Root, 0);
//        ui->clientsTableWidget->sortByColumn(1, Qt::AscendingOrder);
//        ui->clientsTableWidget->sortByColumn(0, Qt::AscendingOrder);
        emit removefromStringList(what->text());
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

void clientsWindow::on_clearButton_clicked()
{
    ui->searchEdit->clear();
    if (!Root) return;
    QMessageBox warning;
    warning.setWindowTitle("Внимание!");
    warning.setText("Очистка этой таблицы приведет к очистке таблицы выдачи/возврата, вы уверены?");
    QAbstractButton* yesButton = warning.addButton(tr("Удалить"), QMessageBox::YesRole);
    warning.addButton(tr("Отмена"), QMessageBox::NoRole);
    warning.exec();
    if (warning.clickedButton() == yesButton){
        Root->clearTree(Root);
        Root = NULL;
        ui->clientsTableWidget->clearContents();
        ui->clientsTableWidget->setRowCount(0);
        List->deleteList();
        emit toReloadTable();
        emit toClear();
    }
    else return;
}

void clientsWindow::addClient()
{
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
//        ui->clientsTableWidget->sortByColumn(1, Qt::AscendingOrder);
//        ui->clientsTableWidget->sortByColumn(0, Qt::AscendingOrder);
        emit addtoStringList(value->getpassportNumber());
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

void clientsWindow::editClient()
{
    try{
        auto what = ui->clientsTableWidget->item(ui->clientsTableWidget->currentRow(), 2);
        QString passport = what->text();
        const long long clientNumber = what->text().remove(4, 1).toLongLong();
        QString newNumber = addDialog->ui->passportNumEdit->text();
        auto occurs = List->searchElement(passport);
        if (occurs.size() != 0 && newNumber != what->text()){
            QMessageBox foundInMoves;
            foundInMoves.setWindowTitle("Внимание!");
            foundInMoves.setText("Изменение номера паспорта этого клиента приведет к удалению всех записей с ним "
                                 "в таблице выдачи/возврата, вы уверены?");
            QAbstractButton* yesButton = foundInMoves.addButton(tr("Да"), QMessageBox::YesRole);
            foundInMoves.addButton(tr("Отмена"), QMessageBox::NoRole);
            foundInMoves.exec();
            if (foundInMoves.clickedButton() == yesButton){
                for (int i = 0; i < occurs.size(); i++){
                    List->remove(occurs[i]->getSimNumber());
                }
                emit removefromStringList(what->text());
                emit toReloadTable();
            }
            else
                return;
        }
        Root = Root->remove(Root, clientNumber);
        addClient();
        emit editClientList();
    }
    catch (myException& ex){
        QMessageBox msg;
        msg.setWindowTitle("Ошибка!");
        msg.setFixedSize(500,400);
        msg.setText(ex.what());
        msg.exec();
        return;
    }
}


clientsObj* clientsWindow::processForm()
{
    return new clientsObj(addDialog->ui->passportNumEdit->text(),
                          addDialog->ui->placeAndDateEdit->text(),
                          addDialog->ui->nameEdit->text(),
                          addDialog->ui->birthDateEdit->text().toInt(),
                          addDialog->ui->adressEdit->text());
}

void clientsWindow::tableReload(clientsTree* Root, int count)
{
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

void clientsWindow::on_searchEdit_textChanged()
{
    QString line;
    if (ui->searchEdit->text().length() == 0)
    {
        ui->clientsTableWidget->clearContents();
        ui->clientsTableWidget->setRowCount(0);
        tableReload(Root, 0);
//        ui->clientsTableWidget->sortByColumn(1, Qt::AscendingOrder);
//        ui->clientsTableWidget->sortByColumn(0, Qt::AscendingOrder);
        return;
    }

    for (int row = 0; row < ui->clientsTableWidget->rowCount(); row++)
    {
        QTableWidgetItem *item = ui->clientsTableWidget->item(row, 2);
        clientsTree* value = Root->findKey(Root, item->text().remove(4,1).toLongLong());
        if (!item) continue;
        clientsObj* client = value->getClient(value);
        ui->searchComboBox->currentIndex() == 0 ? line = client->getpassportNumber() : line = client->getName();
        QVector<int> occurrences = searchEngine::directSearch(line, ui->searchEdit->text());
        if (!occurrences.empty())
            ui->clientsTableWidget->showRow(row);
        else
            ui->clientsTableWidget->hideRow(row);
    }
}
