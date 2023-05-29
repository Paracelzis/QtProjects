#include "clientstree.h"

clientsTree::clientsTree()
{

}


clientsTree::clientsTree(clientsObj* client)
{
    QString number = client->getpassportNumber();
    number = number.remove(4, 1);
    //qDebug() << number;
    this->key = number.toLongLong();
    //qDebug() << key;
    this->client = client;
    this->left = this->right = NULL;
    this->height = 1;
}

long long clientsTree::getKey(clientsTree* node)
{
    return node ? node->key : 0;
}

int clientsTree::getHeight(clientsTree* node)
{
    return node ? node->height : 0;
}

clientsTree* clientsTree::getLeft(clientsTree* node){
    return node->left ? node->left : NULL;
}

clientsTree* clientsTree::getRight(clientsTree* node){
    return node->right ? node->right : NULL;
}

clientsObj* clientsTree::getClient(clientsTree* node){
    return node->client;
}

long clientsTree::bfactor(clientsTree* node)
{
    return getHeight(node->right) - getHeight(node->left);
}

void clientsTree::fixheight(clientsTree* node)
{
    long hl = getHeight(node->left);
    long hr = getHeight(node->right);
    node->height = ((hl>hr) ? hl : hr) + 1;
}

clientsTree* clientsTree::rotateright(clientsTree* node) // правый поворот вокруг p
{
    clientsTree* q = node->left;
    node->left = q->right;
    q->right = node;
    fixheight(node);
    fixheight(node);
    return q;
}

clientsTree* clientsTree::rotateleft(clientsTree* q) // левый поворот вокруг q
{
    clientsTree* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

clientsTree* clientsTree::balance(clientsTree* node) // балансировка узла p
{
    fixheight(node);
    if( bfactor(node) == 2)
    {
        if( bfactor(node->right) < 0)
            node->right = rotateright(node->right);
        return rotateleft(node);
    }
    if (bfactor(node) == -2)
    {
        if (bfactor(node->left) > 0)
            node->left = rotateleft(node->left);
        return rotateright(node);
    }
    return node; // балансировка не нужна
}

clientsTree* clientsTree::insert(clientsTree* node, clientsObj* client) // вставка ключа k в дерево с корнем p
{
    QString number = client->getpassportNumber();
    long long k = number.remove(4,1).toLongLong();
    if (!node)
        return new clientsTree(client);
    if(k < node->key)
        node->left = insert(node->left, client);
    else
        node->right = insert(node->right, client);
    return balance(node);
}

clientsTree* clientsTree::findmin(clientsTree* p) // поиск узла с минимальным ключом в дереве p
{
    return p->left?findmin(p->left):p;
}

clientsTree* clientsTree::removemin(clientsTree* node) // удаление узла с минимальным ключом из дерева p
{
    if(node->left == NULL)
        return node->right;
    node->left = removemin(node->left);
    return balance(node);
}

clientsTree* clientsTree::remove(clientsTree* node, long long k) // удаление ключа k из дерева p
{
    if (!node)
        return 0;
    if (k < node->key)
        node->left = remove(node->left,k);
    else if ( k > node->key )
        node->right = remove(node->right,k);
    else
    {
        clientsTree* q = node->left;
        clientsTree* r = node->right;
        delete node;
        if (!r)
            return q;
        clientsTree* min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    return balance(node);
}

clientsTree* clientsTree::findKey(clientsTree* node, long long key) // поиск узла с ключом k в дереве node
{
    if (!node)
        return NULL;
    if (key == node->key)
        return node;
    if (key < node->key) {
        if (node->left == NULL)
            return NULL;
        findKey(node->left, key);
    }
    else {
        if (node->right == NULL)
            return NULL;
        findKey(node->right, key);
    }
}

void clientsTree::clearTree(clientsTree* node){
    if (!node) return;
    clearTree(node->left);
    clearTree(node->right);
    delete node;
}

void clientsTree::clientsToList(clientsTree* node, QStringList *list){
    if (!node) return;
    this->client = node->getClient(node);
    list->append(client->getpassportNumber());
    clientsToList(node->getRight(node), list);
    clientsToList(node->getLeft(node), list);
}
