#ifndef ADDINHASHDIALOG_H
#define ADDINHASHDIALOG_H

#include <QDialog>

#include <QRegularExpression>
#include <QRegularExpressionValidator>

namespace Ui {
class addinhashdialog;
}

class addinhashdialog : public QDialog
{
    Q_OBJECT

public:
    explicit addinhashdialog(QWidget *parent = nullptr);
    ~addinhashdialog();
    Ui::addinhashdialog *ui;
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

#endif // ADDINHASHDIALOG_H
