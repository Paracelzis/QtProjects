#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
    // Инициализируем второе окно

    clientsWindow_1 = new clientsWindow(this->Root, this->hashTable, this->List);
    infosimWindow_1 = new infosimWindow(this->Root, this->hashTable, this->List);
    issueorrefundsimWindow_1 = new issueorrefundsimWindow(this->List, this->Root, this->hashTable, this->clientsWindow_1,
                                                          this->infosimWindow_1, this->clientsWindow_1->addDialog, this->infosimWindow_1->addDialog);

    // подключаем к слоту запуска главного окна по кнопке во втором окне
    connect(clientsWindow_1, &clientsWindow::menuWindow, this, &menu::show);
    connect(infosimWindow_1, &infosimWindow::menuWindow, this, &menu::show);
    connect(issueorrefundsimWindow_1, &issueorrefundsimWindow::menuWindow, this, &menu::show);
}

menu::~menu()
{
    delete ui;
}

void menu::on_clientsButton_clicked()
{
    clientsWindow_1->show();
    this->close();
}

void menu::on_simInfoButton_clicked()
{
    infosimWindow_1->show();
    this->close();
}

void menu::on_issuOrRefundButton_clicked()
{
    issueorrefundsimWindow_1->show();
    this->close();
}

