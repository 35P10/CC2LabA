#include "Node.h"
#include <iostream>
using namespace std;

Node::Node()
{
    x = NULL;
    next = NULL;
}

Node::Node(int new_x)
{
    x = new_x;
    next = NULL;
}

Node::~Node()
{

}

int Node::getX()
{
    return x;
}

void Node::Delete_this()
{
    if (next)
        next->Delete_this();
    delete this;
}


void Node::Printnode()
{
    cout<<x<<"->";
}

