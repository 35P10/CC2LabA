#include "Node.h"
#include <iostream>
using namespace std;

class Iterator
{
private:
    Node *ptr;
    friend class LinkedList;
public:

    Iterator(Node* x);
    Iterator &operator++() {
        ptr = ptr->next;
        return *this;
    }
    Iterator operator++(int)
    {
        Iterator iterator = *this;
        ++*this;
        return iterator;
    }

    Iterator& operator=(Node* ptr)
    {
        this->ptr = ptr;
        return *this;
    }

    Iterator& operator=(Iterator* iterato)
    {
        this->ptr = iterato->ptr;
        return *this;
    }
    bool operator!=(const Iterator& itr) const {
        return ptr != itr.ptr;
    }

    int operator*()
    {
        return ptr->x;
    }

};


Iterator::Iterator(Node* x)
{
    ptr=x;
}


