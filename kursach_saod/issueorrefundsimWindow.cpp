#include "issueorrefundsimWindow.h"
#include "ui_issueorrefundsimWindow.h"

issueorrefundsimWindow::issueorrefundsimWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::issueorrefundsimWindow)
{
    ui->setupUi(this);
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
