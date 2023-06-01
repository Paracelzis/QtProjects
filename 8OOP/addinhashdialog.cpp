#include "addinhashdialog.h"
#include "ui_addinhashdialog.h"

addinhashdialog::addinhashdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addinhashdialog),
    validator(QRegularExpression("[0-9]{3}-[0-9]{7}")),
    validator2(QRegularExpression("[1-2][0-9]{3}"))
{
    ui->setupUi(this);

    ui->simNumberEdit->setValidator(&validator);
    ui->yearEdit->setValidator(&validator2);

    connect(ui->doneButton, &QPushButton::clicked, this, &addinhashdialog::doneButtonClicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &addinhashdialog::cancelButtonClicked);
}

addinhashdialog::~addinhashdialog()
{
    delete ui;
}

void addinhashdialog::doneButtonClicked(){
    this->sender->text() == "Добавить" ? emit readytoAdd() : emit readytoEdit();
}

void addinhashdialog::cancelButtonClicked(){
    this->close();
}


