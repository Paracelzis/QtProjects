#ifndef MYLISTNODE_H
#define MYLISTNODE_H

#include <issueorrefundsimobj.h>

class myListNode
{
public:
    ~myListNode();
    myListNode(issueorrefundsimObj* data);
    issueorrefundsimObj* data;
    myListNode* next;
};

#endif // MYLISTNODE_H
