#include "Iterator.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

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
            New_node->next=head;
            head = New_node;
            //cout<<"Head reasignado\n";
    }
    size++;
}

void LinkedList::insertNodeB(int x)
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
        insertNode(x);
    }
    else if (j==size)
    {
        insertNodeB(x);
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


