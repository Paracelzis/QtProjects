#include "issueorrefundsimWindow.h"
#include "ui_issueorrefundsimWindow.h"

#include "ui_addinhashdialog.h"
#include "ui_addinlistdialog.h"
#include "ui_addintreedialog.h"

issueorrefundsimWindow::issueorrefundsimWindow(mylist *&List, clientsTree *&Root, myHashTable *&hashTable,
                                               clientsWindow*& clientsWindow_1, infosimWindow*& infosimWindow_1,
                                               addInTreeDialog*& addTreeDialog, addinhashdialog*& addHashDialog,
                                               QWidget *parent) :
    QWidget(parent),
    ui(new Ui::issueorrefundsimWindow),
    Root(Root),
    hashTable(hashTable),
    List(List),
    infosimWindow_1(infosimWindow_1),
    clientsWindow_1(clientsWindow_1),
    addTreeDialog(addTreeDialog),
    addHashDialog(addHashDialog)

{
    ui->setupUi(this);

    addNoteDialog = new addinlistdialog();

    connect(ui->addButton, &QPushButton::clicked, this, &issueorrefundsimWindow::addButtonClicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &issueorrefundsimWindow::deleteButtonClicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &issueorrefundsimWindow::clearButtonClicked);
    connect(ui->searchEdit, &QLineEdit::textChanged, this, &issueorrefundsimWindow::searchTextChanged);
    connect(ui->editButton, &QPushButton::clicked, this, &issueorrefundsimWindow::editButtonClicked);
    connect(addNoteDialog, &::addinlistdialog::readytoAdd, this, &issueorrefundsimWindow::addNote);
    connect(addNoteDialog, &::addinlistdialog::readytoEdit, this, &issueorrefundsimWindow::editNote);

    connect(clientsWindow_1, &clientsWindow::toReloadTable, this, &issueorrefundsimWindow::tableReload);
    connect(infosimWindow_1, &infosimWindow::toReloadTable, this, &issueorrefundsimWindow::tableReload);
    //new stuff
    connect(clientsWindow_1, &clientsWindow::addtoStringList, this, &issueorrefundsimWindow::addinClientsList);
    connect(clientsWindow_1, &clientsWindow::editClientList, this, &issueorrefundsimWindow::editClientsList);
    connect(clientsWindow_1, &clientsWindow::removefromStringList, this, &issueorrefundsimWindow::removefromClientsList);
    connect(clientsWindow_1, &clientsWindow::toClear, this, &issueorrefundsimWindow::clearClientsList);
    connect(infosimWindow_1, &infosimWindow::addinList, this, &issueorrefundsimWindow::addinInfoSimList);
    connect(infosimWindow_1, &infosimWindow::removefromList, this, &issueorrefundsimWindow::removefromInfoSimList);
    connect(infosimWindow_1, &infosimWindow::toClear, this, &issueorrefundsimWindow::clearInfoSimList);

}

issueorrefundsimWindow::~issueorrefundsimWindow()
{
    delete ui;
}

void issueorrefundsimWindow::on_menuExitButton_clicked()
{
    this->close();
    emit menuWindow();
}

// done
void issueorrefundsimWindow::addinClientsList(QString client){
    clientsList << client;
    setClientsCompleter();
}

void issueorrefundsimWindow::removefromClientsList(QString client){
    clientsList.removeOne(client);
    setClientsCompleter();
}

void issueorrefundsimWindow::editClientsList(){
    tableReload();
}

void issueorrefundsimWindow::setClientsCompleter(){
    clientCompleter = new QCompleter(clientsList, this);
    clientCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    addNoteDialog->ui->passportEdit->setCompleter(clientCompleter);
}

void issueorrefundsimWindow::addinInfoSimList(QString res){
    infosimList << res;
    setInfoSimCompleter();
}

void issueorrefundsimWindow::removefromInfoSimList(QString res){
    infosimList.removeOne(res);
    setInfoSimCompleter();
}

void issueorrefundsimWindow::setInfoSimCompleter(){
    infosimCompleter = new QCompleter(infosimList, this);
    infosimCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    addNoteDialog->ui->simNumberEdit->setCompleter(infosimCompleter);
}

void issueorrefundsimWindow::clearClientsList(){
    clientsList.clear();
    setClientsCompleter();
}

void issueorrefundsimWindow::clearInfoSimList(){
    clientsList.clear();
    setInfoSimCompleter();
}





//
issueorrefundsimObj* issueorrefundsimWindow::processForm(){
    return new issueorrefundsimObj(addNoteDialog->ui->passportEdit->text(), addNoteDialog->ui->simNumberEdit->text(),
                        addNoteDialog->ui->issueDateEdit->text(), addNoteDialog->ui->endDateEdit->text());
}

void issueorrefundsimWindow::addButtonClicked(){
    QPushButton* pressed = (QPushButton* )sender();
    addNoteDialog->sender = pressed;
    addNoteDialog->exec();
}

void issueorrefundsimWindow::tableReload(){

    ui->isuueorrefundTableWidget->clearContents();
    ui->isuueorrefundTableWidget->setRowCount(0);

    if (List->getHeader() == nullptr)
        return;


    QVector<issueorrefundsimObj*> listElements;
    myListNode* current = List->getHeader();

    do {
        listElements.push_back(current->data);
        current = current->next;
    }
    while (current != List->getHeader());

    shakerSort(listElements);

    for (int i = 0; i < listElements.size(); i++)
    {
        ui->isuueorrefundTableWidget->insertRow(i);
        ui->isuueorrefundTableWidget->setItem(i, 0, new QTableWidgetItem(listElements[i]->getSimNumber()));
        ui->isuueorrefundTableWidget->setItem(i, 1, new QTableWidgetItem(listElements[i]->getPassportNumber()));

        clientsTree *tmpnode = Root->findKey(Root, listElements[i]->getPassportNumber().remove(4,1).toLongLong());
        QString tmp = tmpnode->getClient(tmpnode)->getName();
        ui->isuueorrefundTableWidget->setItem(i, 2, new QTableWidgetItem(tmp));

        ui->isuueorrefundTableWidget->setItem(i, 3, new QTableWidgetItem(listElements[i]->getIssueDate()));
        ui->isuueorrefundTableWidget->setItem(i, 4, new QTableWidgetItem(listElements[i]->getEndDate()));
    }
}

void issueorrefundsimWindow::addNote(){
    try {
        auto value = processForm();
        clientsTree* tmp = Root->findKey(Root, value->getPassportNumber().remove(4, 1).toLongLong());
        if (tmp == NULL){
            QMessageBox noClient;
            noClient.setWindowTitle("Добавьте клиента");
            noClient.setText("Такого клиента еще нет. Добавить его?");
            QAbstractButton* yesButton = noClient.addButton(tr("Да"), QMessageBox::YesRole);
            QAbstractButton* noButton = noClient.addButton(tr("Нет"), QMessageBox::NoRole);
            noClient.exec();
            if (noClient.clickedButton() == yesButton){
                addTreeDialog->sender = this->ui->addButton;
                addTreeDialog->ui->passportNumEdit->setText(value->getPassportNumber());
                addTreeDialog->exec();
            }
            return;
        }
        infosimObj* restmp = hashTable->search(value->getSimNumber());

        if (restmp == NULL){
            QMessageBox noSim;
            noSim.setWindowTitle("Добавьте SIM-карту");
            noSim.setText("Такой SIM-карты еще нет. Добавить её?");
            QAbstractButton* yesButton = noSim.addButton(tr("Да"), QMessageBox::YesRole);
            QAbstractButton* noButton = noSim.addButton(tr("Нет"), QMessageBox::NoRole);
            noSim.exec();
            if (noSim.clickedButton() == yesButton){
                addHashDialog->sender = this->ui->addButton;
                addHashDialog->ui->simNumberEdit->setText(value->getSimNumber());
                addHashDialog->ui->rateEdit->clear();
                addHashDialog->ui->yearEdit->clear();
                addHashDialog->exec();
            }
            return;
        }

        restmp->isThere = 1;

        if (List->find(value->getSimNumber()) != NULL)
            throw myException("У SIM-карты уже есть владелец.");
        List->add(value);
        addNoteDialog->close();
        ui->isuueorrefundTableWidget->clearContents();
        ui->isuueorrefundTableWidget->setRowCount(0);
        tableReload();
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

void issueorrefundsimWindow::deleteButtonClicked(){
    try{
        if (ui->isuueorrefundTableWidget->currentRow() < 0)
            throw myException("Не выбрана строка для удаления");
        auto whatsim = ui->isuueorrefundTableWidget->item(ui->isuueorrefundTableWidget->currentRow(), 0);
        QString sim = whatsim->text();
        List->remove(sim);

        auto value = processForm();
        infosimObj* restmp = hashTable->search(value->getSimNumber());
        restmp->isThere = 0;
        tableReload();
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

void issueorrefundsimWindow::editButtonClicked(){
    try{
        if (ui->isuueorrefundTableWidget->currentRow() < 0)
            throw myException("Не выбрана строка для редактирования");
        auto whatsim = ui->isuueorrefundTableWidget->item(ui->isuueorrefundTableWidget->currentRow(), 0);
        QString sim = whatsim->text();
        issueorrefundsimObj* tmp = List->find(sim);
        QPushButton* pressed = (QPushButton* )sender();
        addNoteDialog->sender = pressed;
        addNoteDialog->ui->passportEdit->setReadOnly(1);
        addNoteDialog->ui->simNumberEdit->setReadOnly(1);
        addNoteDialog->ui->simNumberEdit->setText(tmp->getSimNumber());
        addNoteDialog->ui->passportEdit->setText(tmp->getPassportNumber());
        addNoteDialog->ui->issueDateEdit->setDate(QDate::fromString(tmp->getIssueDate()));
        addNoteDialog->ui->endDateEdit->setDate(QDate::fromString(tmp->getEndDate()));
        addNoteDialog->exec();
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

void issueorrefundsimWindow::editNote(){
    try {
        auto whatpassport = ui->isuueorrefundTableWidget->item(ui->isuueorrefundTableWidget->currentRow(), 1);
        List->findandSet(whatpassport->text(),
                         addNoteDialog->ui->issueDateEdit->text(),
                         addNoteDialog->ui->endDateEdit->text());
        addNoteDialog->close();
        tableReload();
    }
    catch(myException &ex){
        QMessageBox msg;
        msg.setWindowTitle("Ошибка!");
        msg.setFixedSize(500,400);
        msg.setText(ex.what());
        msg.exec();
        return;
    }

}

void issueorrefundsimWindow::clearButtonClicked(){
    List->deleteList();
    tableReload();
}

void issueorrefundsimWindow::shakerSort(QVector<issueorrefundsimObj*>& arr){
    int control = arr.size() - 1;
    int left  = 0;
    int right = arr.size() - 1;
    do {
        for (int i = left; i < right; i++) {
            if (arr[i]->getSimNumber().remove(3,1).toLongLong() > arr[i + 1]->getSimNumber().remove(3,1).toLongLong()) {
                auto tmp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = tmp;
                control = i;
            }
        }
        right = control;
        for (int i = right; i > left; i--) {
            if (arr[i]->getSimNumber().remove(3,1).toLongLong() < arr[i - 1]->getSimNumber().remove(3,1).toLongLong()) {
                auto tmp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = tmp;
                control = i;
            }
        }
        left = control;
    } while (left < right);
}



void issueorrefundsimWindow::searchTextChanged(){
    QString line;
    if (ui->searchEdit->text().length() == 0){
        ui->isuueorrefundTableWidget->clearContents();
        ui->isuueorrefundTableWidget->setRowCount(0);
        tableReload();
        return;
    }
    for (int row = 0; row < ui->isuueorrefundTableWidget->rowCount(); row++) {
        QTableWidgetItem *itemSim = ui->isuueorrefundTableWidget->item(row, 0);
        issueorrefundsimObj* value = List->find(itemSim->text());
        if (!value) continue;
        ui->searchComboBox->currentIndex() == 0 ? line = value->getPassportNumber() : line = value->getSimNumber();
        QVector<int> occurrences = searchEngine::directSearch(line, ui->searchEdit->text());
        if (!occurrences.empty())
            ui->isuueorrefundTableWidget->showRow(row);
        else
            ui->isuueorrefundTableWidget->hideRow(row);
    }
}

