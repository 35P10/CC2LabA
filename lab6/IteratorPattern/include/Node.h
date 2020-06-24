#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template<typename T>
class Node
{
private:
    //T x;
	//Node *next;

public:
    //no había otra manera :'v
    T x;
	Node *next;

    Node();
    Node(T new_x);
    ~Node();

    int getX();
    void Delete_this();
    void Printnode();

    //friend class LinkedList;
};
template class Node<int>;
template class Node<double>;

#endif // NODE_H
