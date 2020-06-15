#include <iostream>
using namespace std;

class Node
{

public:
    int x;
	Node *next;

    Node();
    Node(int new_x);
    ~Node();

    int getX();
    void Delete_this();
    void Printnode();
};


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

LinkedList::LinkedList()
{
    size = 0;
    head = NULL;
}

LinkedList::LinkedList(int x)
{
    size = 0;
    head = new Node(x);
}

void LinkedList::insertNode(int x)
{
    Node *cont = head;
    Node *New_node = new Node(x);

    if (head==NULL)
    {
        head = New_node;
    }
    else
    {
        if (New_node->x < head->x)
        {
            New_node->next=head;
            head = New_node;
            cout<<"Head reasignado\n";
        }
        else
        {
            while((cont->next!=NULL) &&(New_node->x > cont->next->x))
                {
                    cont = cont->next;
                }
                    New_node->next = cont->next;
                    cont->next = New_node;

        }
    }
    size++;
}

void LinkedList::removeNode(int x)
{
    Node *cont = head;
    Node *cont2 = head->next;

    if(head->x==x)
    {
        head= cont->next;
        cout<<"Head eliminado\n";
    }
    else
    {
    while (cont2!=NULL)
    {
        if (cont2->x == x)
        {
            cont->next = cont2->next;
            break;
        }
        else
        {
        cont = cont->next;
        cont2 = cont2->next;
        }
    }
    }
    if (cont2==NULL)
        cout<<"Elemento no encontrado\n";
}

void LinkedList::printLinkedList()
{
    if ((size==0)&&(head==NULL))
    {
        cout<<"Lista Vacia\n";
    }
    else if ((size==0)&&(head!=NULL))
    {
        head->Printnode();
    }
    else
    {
        Node *i = head;

        while(i!=NULL)
        {
        i->Printnode();
        i=i->next;
        }
        cout<<endl;
    }
}

int main()
{
LinkedList a(6);
a.insertNode(7);
a.insertNode(9);
a.insertNode(10);
cout<<"Lista original:\n";
a.printLinkedList();
cout<<"Lista: insertando el elemento 8 , 11 y 5:\n";
a.insertNode(8);
a.insertNode(11);
a.insertNode(5);
a.printLinkedList();
cout<<"Lista:eliminando el elemento 5 y 8:\n";
a.removeNode(8);

a.printLinkedList();
cout<<"Lista:eliminando 100\n";
a.removeNode(100);
a.printLinkedList();
}




