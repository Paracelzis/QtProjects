#ifndef ADDINLISTDIALOG_H
#define ADDINLISTDIALOG_H

#include <QDialog>
#include <QCompleter>

#include <QRegularExpression>
#include <QRegularExpressionValidator>

namespace Ui {
class addinlistdialog;
}

class addinlistdialog : public QDialog
{
    Q_OBJECT

public:
    explicit addinlistdialog(QWidget *parent = nullptr);
    ~addinlistdialog();
    Ui::addinlistdialog *ui;
    QPushButton* sender;

signals:
    void readytoAdd();
    void readytoEdit();

private slots:
    void doneButtonClicked();
    void cancelButtonClicked();

private:
    QRegularExpressionValidator validator, validator2;
};

#endif // ADDINLISTDIALOG_H
