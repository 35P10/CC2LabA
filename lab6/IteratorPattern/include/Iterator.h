#include "Node.h"
#include <iostream>
using namespace std;

template<typename T>
class Iterator
{
private:
    Node<T> *ptr;
    //template<T> friend class LinkedList;
public:

    Iterator(Node<T>* x){
    ptr=x;
    }

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

    Iterator& operator=(Node<T>* ptr)
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

