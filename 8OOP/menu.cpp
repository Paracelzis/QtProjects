#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);

    windows = new windowsfacade(this->List,this->Root, this->hashTable);
    connect(windows, &windowsfacade::showMenu, this, &menu::show);

    connect(ui->clientsButton, &QPushButton::clicked, this, &menu::buttonClicked);
    connect(ui->simInfoButton, &QPushButton::clicked, this, &menu::buttonClicked);
    connect(ui->issuOrRefundButton, &QPushButton::clicked, this, &menu::buttonClicked);
}

menu::~menu()
{
    delete ui;
}

void menu::buttonClicked()
{
    QPushButton* pressed = (QPushButton* )sender();
    windows->showWindow(pressed);
    this->close();
}


