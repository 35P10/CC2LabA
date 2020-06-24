#include "Node.h"
#include <iostream>
using namespace std;

template<class T>
Node<T>::Node()
{
    x = NULL;
    next = NULL;
}

template<class T>
Node<T>::Node(T new_x)
{
    x = new_x;
    next = NULL;
}

template<class T>
Node<T>::~Node()
{

}

template<class T>
int Node<T>::getX()
{
    return x;
}

template<class T>
void Node<T>::Delete_this()
{
    if (next)
        next->Delete_this();
    delete this;
}

template<class T>
void Node<T>::Printnode()
{
    if (next!=NULL)
        cout<<x<<"->";
    else
        cout<<x;
}
