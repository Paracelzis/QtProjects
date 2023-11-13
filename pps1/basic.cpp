#include "basic.h"
#include "ui_basic.h"

basic::basic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::basic)
{
    ui->setupUi(this);
}

basic::~basic()
{
    delete ui;
}
