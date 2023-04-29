#ifndef CLIENTSTREE_H
#define CLIENTSTREE_H

#include <clientsobj.h>

class clientsTree
{
public:
    clientsTree();
    clientsTree(clientsObj* client);
    long long getKey(clientsTree* node);
    int getHeight(clientsTree* node);
    clientsTree* getLeft(clientsTree* node);
    clientsTree* getRight(clientsTree* node);
    clientsObj* getClient(clientsTree* node);
    long bfactor(clientsTree* node);
    void fixheight(clientsTree* p);
    clientsTree* rotateright(clientsTree* p);
    clientsTree* rotateleft(clientsTree* q);
    clientsTree* balance(clientsTree* p);
    clientsTree* insert(clientsTree* node, clientsObj* client);
    clientsTree* findmin(clientsTree* p);
    clientsTree* removemin(clientsTree* node);
    clientsTree* remove(clientsTree* node, long long k);
    clientsTree* findKey(clientsTree* node, long long k);
    void clearTree(clientsTree* node);
private:
    long long key;
    int height;
    clientsObj* client;
    clientsTree* left;
    clientsTree* right;
};

#endif // CLIENTSTREE_H
