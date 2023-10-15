#include "mylist.h"


mylist::mylist()
{
    head = nullptr;
}


mylist::~mylist()
{
    if (head == nullptr)
        return;
    myListNode *current = head;
    while (current->next != head) {
        myListNode *temp = current;
        current = current->next;
        delete temp;
    }
    delete current;
    head = nullptr;
}

void mylist::add(issueorrefundsimObj* obj) {
    myListNode* newNode = new myListNode(obj);
    if (head == nullptr) {
        // Если список пуст, новый узел становится головой
        head = newNode;
        head->next = head;
    }
    else {
        myListNode *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
}

void mylist::remove(QString data) {
    if (head == nullptr) {
        return;
    }

    myListNode* current = head;
    myListNode* prev = nullptr;
    do {
        if (current->data->getSimNumber() == data) {
            if (prev == nullptr) {
                // Удаляем голову
                if (head->next == head) {
                    // Если в списке только один элемент
                    head = nullptr;
                }
                else {
                    myListNode* last = head;
                    while (last->next != head) {
                        last = last->next;
                    }
                    head = head->next;
                    last->next = head;
                }
            }
            else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    } while (current != head);
}




issueorrefundsimObj* mylist::find(QString data)  {
    if (head == nullptr) {
        return nullptr;
    }

    myListNode* current = head;
    do {
        if (current->data->getSimNumber() == data) {
            return current->data;
        }
        current = current->next;
    }
    while (current != head);
    return nullptr; // Элемент не найден
}


QVector<issueorrefundsimObj*> mylist::searchElement(QString key){

    QVector<issueorrefundsimObj*> occurances;
    myListNode* current = head;

    if (current == NULL)
    {
        return occurances;
    }

    do {
        if (current->data->getPassportNumber() == key){
            occurances.push_back(current->data);
            current = current->next;
        }
        else
            current = current->next;
    }
    while (current != head);

    return occurances;
}

bool mylist::findandSet(QString passport, QString IssueDate, QString EndDate){
    myListNode* current = head;
    if (current == nullptr) return 0;
    do {
        if (current->data->getPassportNumber() == passport) {
            current->data->setIssueDate(IssueDate);
            current->data->setEndDate(EndDate);
            return 1;
        }
        current = current->next;
    } while (current != head);
    return 0;
}

bool mylist::findandSet(QString searchPassport, QString newPassport){
    myListNode* current = head;
    if (current == nullptr)
        return 0;
    do {
        if (current->data->getPassportNumber() == searchPassport){
            current->data->setPassportNumber(newPassport);
            return 1;
        }
        current = current->next;
    } while (current != head);
    return 0;
}

int mylist::countElement(){
    if (head == nullptr) {
        return 0;
    }
    myListNode* current = head;
    int count = 1;

    while (current->next != head) {
        count++;
        current = current->next;
    }
    return count;
}

void mylist::deleteList() {
    if (head == nullptr)
        return;
    myListNode *current = head->next;
    while (current->next != head) {
        myListNode *temp = current;
        current = current->next;
        delete temp;
    }
    current = head;
    head = nullptr;
}
