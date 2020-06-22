#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include "LinkedList.h"
#include "Iterator.h"
using namespace std;

class LinkedList
{
private:
        Node *head;
        Node *tail;
        int size;
public:
        LinkedList();
        LinkedList(int x);
        void insertHead(int x);
        void insertTail(int x);
        void insertNodeC(int x,int i);
        void removeNode(int x);
        void printLinkedList();
        int getSize();
        Iterator begin();
        Iterator end();
};

int LinkedList::getSize()
{
    return size;
}


LinkedList::LinkedList()
{
    size = 0;
    head = NULL;
    tail = NULL;
}

LinkedList::LinkedList(int x)
{
    size = 1;
    head = new Node(x);
}

void LinkedList::insertHead(int x)
{

    Node *New_node = new Node(x);

    if (head==NULL)
    {
        head = New_node;
    }
    else
    {
            New_node->next=head;
            head = New_node;
            //cout<<"Head reasignado\n";
    }
    size++;
}

void LinkedList::insertTail(int x)
{
    Node *cont = head;
    Node *New_node = new Node(x);

    if (head==NULL)
    {
        head = New_node;
    }
    else
    {
        while((cont->next!=NULL))
        {
            cont = cont->next;
        }
                cont->next = New_node;
                tail = New_node;
    }
    size++;
}

void LinkedList::insertNodeC(int x,int j)
{
    Node *cont = head;
    Node *New_node = new Node(x);

    if (j==1)
    {
        insertHead(x);
    }
    else if (j==size)
    {
        insertTail(x);
    }
    else if (j>size)
    {
        cout<<"No permitido";
    }

    else
    {
        for(int i=2;i<j;i++)
        {
            cont = cont->next;
        }
                New_node->next = cont->next;
                cont->next = New_node;
        size++;
    }
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
    size--;
    }
    if (cont2==NULL)
        cout<<"Elemento no encontrado\n";

}

Iterator LinkedList::begin()
{
        return Iterator(head);
}

Iterator LinkedList::end()
{
        return Iterator(tail);
}

void LinkedList::printLinkedList()
{
    Iterator cont (head);
    while(cont.ptr!=NULL)
    {
    cont.ptr->Printnode();
    cont++;
    cout<<endl;
    }

}

#endif // LINKEDLIST_H
