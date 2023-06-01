#ifndef WINDOWSFACADE_H
#define WINDOWSFACADE_H

#include <QObject>
#include <clientsWindow.h>
#include <infosimWindow.h>
#include <issueorrefundsimWindow.h>
#include <QPushButton>


class windowsfacade : public QObject
{
    Q_OBJECT
public:
    explicit windowsfacade(mylist*& List, clientsTree*& Root, myHashTable*& hashTable, QWidget *parent = nullptr);
    void showWindow(const QPushButton* sender);
    void closeWindow();

signals:
    void showMenu();

private:
    clientsWindow* clientsWindow_1;
    infosimWindow* infosimWindow_1;
    issueorrefundsimWindow* issueorrefundsimWindow_1;
};

#endif // WINDOWSFACADE_H
