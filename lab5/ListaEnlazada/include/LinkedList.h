#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList
{
private:
        Node *head;
        int size;
public:
        LinkedList();
        LinkedList(int x);
        void insertNode(int x);
        void removeNode(int x);
        void printLinkedList();
};


#endif // LINKEDLIST_H
