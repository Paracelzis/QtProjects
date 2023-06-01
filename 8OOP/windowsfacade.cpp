#include "windowsfacade.h"

windowsfacade::windowsfacade(mylist*& List, clientsTree*& Root, myHashTable*& hashTable, QWidget *parent)
    : QObject{parent}
{
    clientsWindow_1 = new clientsWindow(Root, hashTable, List);
    infosimWindow_1 = new infosimWindow(Root, hashTable, List);
    issueorrefundsimWindow_1 = new issueorrefundsimWindow(List, Root, hashTable, this->clientsWindow_1,
                                                          this->infosimWindow_1, this->clientsWindow_1->addDialog, this->infosimWindow_1->addDialog);

    connect(clientsWindow_1, &clientsWindow::menuWindow, this, &windowsfacade::closeWindow);
    connect(infosimWindow_1, &infosimWindow::menuWindow, this, &windowsfacade::closeWindow);
    connect(issueorrefundsimWindow_1, &issueorrefundsimWindow::menuWindow, this, &windowsfacade::closeWindow);
}

void windowsfacade::showWindow(const QPushButton *sender){
    if (sender->objectName() == "clientsButton"){
        clientsWindow_1->show();
    }
    if (sender->objectName() == "simInfoButton"){
        infosimWindow_1->show();
    }
    if (sender->objectName() == "issuOrRefundButton"){
        issueorrefundsimWindow_1->show();
    }
}

void windowsfacade::closeWindow(){
    emit showMenu();
}
