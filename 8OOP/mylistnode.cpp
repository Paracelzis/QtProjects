#include "mylistnode.h"

myListNode::~myListNode(){}

myListNode::myListNode(issueorrefundsimObj* data)
{
    this->data = data;
    this->next = nullptr;
}
