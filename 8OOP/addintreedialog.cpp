#include "addintreedialog.h"
#include "ui_addintreedialog.h"

addInTreeDialog::addInTreeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addInTreeDialog),
    validator(QRegularExpression("[0-9]{4}-[0-9]{6}")),
    validator2(QRegularExpression("[1-2][0-9]{3}"))
{
    ui->setupUi(this);

    ui->passportNumEdit->setValidator(&validator);
    ui->birthDateEdit->setValidator(&validator2);

}

addInTreeDialog::~addInTreeDialog()
{
    delete ui;
}

void addInTreeDialog::on_cancelButton_clicked()
{
    this->close();
}

void addInTreeDialog::on_addButton_clicked()
{
    this->sender->text() == "Добавить" ? emit readyToAdd(): emit readyToEdit();
}

