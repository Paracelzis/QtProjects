#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include <infosimobj.h>
#include <cmath>

class myHashTable
{
public:
    myHashTable();
    infosimObj** arr;
    int capacity, size;
    infosimObj* dummy;
    void insertNode(infosimObj* resident);
    bool deleteNode(QString simNumber);
    infosimObj* search(QString simNumber);
    bool isEmpty();
    int sizeofTable();
    void clear();
};

int hash(QString simNumber);

#endif // MYHASHTABLE_H
