#include "myhashtable.h"

myHashTable::myHashTable()
{
    this->capacity = 2500;
    this->size = 0;
    this->arr = new infosimObj*[capacity];
    for (int i = 0; i < capacity; i++)
        arr[i] = NULL;
    this->dummy = new infosimObj();
}

int hash(QString simNumber)
{
    int hash_result = 0;
    for (int i = 0; i < simNumber.size(); i++)
        hash_result += ((2500 / (i + 10)) * hash_result + simNumber[i].digitValue()) % 2500;
    //qDebug() << (hash_result * 2) % 2500;
    return (hash_result * 2) % 2500;
}

void myHashTable::insertNode(infosimObj* human)
{
    int key = hash(human->getsimNumber().remove(3, 1));
    int counter = 1;
    while (arr[key] != NULL && arr[key]->getYear() == -1)
    {
        key = (key + counter) % capacity;
        counter++;
        //qDebug() << key;
    }
    if (arr[key] == NULL || arr[key]->getYear() == -1)
    {
        size++;
        arr[key] = human;
        //qDebug() << key;
    }
}

bool myHashTable::deleteNode(QString simNumber)
{
    int counter = 1;
    QString tmp = simNumber;
    int key = hash(tmp.remove(3, 1));
    while (arr[key] != NULL){
        if (arr[key]->getsimNumber() == simNumber)
        {
            arr[key] = dummy;
            size--;
            return 1;
        }
    key = (key + counter) % capacity;
    counter++;
  }
  return 0;
}

infosimObj* myHashTable::search(QString simNumber)
{
    int counter = 1;
    QString tmp = simNumber;
    int key = hash(tmp.remove(3, 1));
    while (arr[key] != NULL)
    {
        if (arr[key]->getsimNumber() == simNumber)
            return arr[key];
        key = (key + counter) % capacity;
        counter++;
    }
  return NULL;
}

int myHashTable::sizeofTable()
{
    return this->size;
}

bool myHashTable::isEmpty()
{
    return this->size == 0;
}

void myHashTable::clear()
{
    for (int i = 0; i < capacity; i++)
    {
        arr[i] = NULL;
        size = 0;
    }
}
