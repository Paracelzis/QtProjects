#include "menu.h"
#include "ui_menu.h"

menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
    // Инициализируем второе окно

    clientsWindow_1 = new clientsWindow();
    infosimWindow_1 = new infosimWindow();
    issueorrefundsimWindow_1 = new issueorrefundsimWindow();

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

