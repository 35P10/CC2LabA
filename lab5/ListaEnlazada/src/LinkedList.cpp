#include "LinkedList.h"
#include <iostream>

using namespace std;

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
    size--;
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

