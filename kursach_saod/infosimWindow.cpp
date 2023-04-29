#include "infosimWindow.h"
#include "ui_infosimWindow.h"

infosimWindow::infosimWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::infosimWindow)
{
    ui->setupUi(this);
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
