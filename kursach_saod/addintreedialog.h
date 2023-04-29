#ifndef ADDINTREEDIALOG_H
#define ADDINTREEDIALOG_H

#include <QDialog>

#include <QRegularExpression>
#include <QRegularExpressionValidator>


namespace Ui {
class addInTreeDialog;
}

class addInTreeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addInTreeDialog(QWidget *parent = nullptr);
    ~addInTreeDialog();
    Ui::addInTreeDialog *ui;
    QPushButton* sender;

signals:
    void readyToAdd();
    void readyToEdit();
private slots:
    void on_cancelButton_clicked();
    void on_addButton_clicked();
private:
    QRegularExpressionValidator validator, validator2;
};

#endif // ADDINTREEDIALOG_H
