#ifndef MYLIST_H
#define MYLIST_H

#include <mylistnode.h>

class mylist
{
public:
    mylist();
    ~mylist();
    void add(issueorrefundsimObj* obj);
    void remove(QString data);
    issueorrefundsimObj* find(QString data);
    myListNode* getHeader(){ return this->head;}
    QVector<issueorrefundsimObj*> searchElement(QString);
    void deleteList();
    bool findandSet(QString, QString, QString);
    bool findandSet(QString, QString);
    int countElement();

private:
    myListNode* head;
};

#endif // MYLIST_H
