#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <windowsfacade.h>

QT_BEGIN_NAMESPACE
namespace Ui { class menu; }
QT_END_NAMESPACE

class menu : public QMainWindow
{
    Q_OBJECT

public:
    menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void buttonClicked();

private:
    Ui::menu *ui;
    clientsTree* Root = NULL;
    myHashTable* hashTable = new myHashTable();
    mylist* List = new mylist();
    windowsfacade* windows;
};
#endif // MENU_H
