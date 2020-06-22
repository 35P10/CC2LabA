#ifndef NODE_H
#define NODE_H


class Node
{
private:
    int x;
	Node *next;

public:

    Node();
    Node(int new_x);
    ~Node();

    int getX();
    void Delete_this();
    void Printnode();

    friend class LinkedList;
    friend class Iterator;
};


#endif // NODE_H
