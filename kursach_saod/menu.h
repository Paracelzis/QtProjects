#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <clientsWindow.h>
#include <infosimWindow.h>
#include <issueorrefundsimWindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class menu; }
QT_END_NAMESPACE

class menu : public QMainWindow
{
    Q_OBJECT

public:
    menu(QWidget *parent = nullptr);
    ~menu();
signals:
    void menuWindow();

private slots:
    void on_clientsButton_clicked();
    void on_simInfoButton_clicked();
    void on_issuOrRefundButton_clicked();

private:
    Ui::menu *ui;
    clientsTree* Root = NULL;
    myHashTable* hashTable = new myHashTable();
    clientsWindow *clientsWindow_1;
    infosimWindow *infosimWindow_1;
    issueorrefundsimWindow *issueorrefundsimWindow_1;
};
#endif // MENU_H
