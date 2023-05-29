#include "addinlistdialog.h"
#include "ui_addinlistdialog.h"

addinlistdialog::addinlistdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addinlistdialog),
    validator(QRegularExpression("[0-9]{4}-[0-9]{6}")),
    validator2(QRegularExpression("[0-9]{3}-[0-9]{7}"))
{
    ui->setupUi(this);

    ui->passportEdit->setValidator(&validator);
    ui->simNumberEdit->setValidator(&validator2);

    connect(ui->doneButton, &QPushButton::clicked, this, &addinlistdialog::doneButtonClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &addinlistdialog::cancelButtonClicked);
}

addinlistdialog::~addinlistdialog()
{
    delete ui;
}

void addinlistdialog::doneButtonClicked(){
    this->sender->text() == "Добавить" ? emit readytoAdd() : emit readytoEdit();
}

void addinlistdialog::cancelButtonClicked(){
    this->close();
}
