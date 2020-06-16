#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

int main()
{
LinkedList a(6);
a.insertNode(7);
a.insertNode(9);
a.insertNode(1);
cout<<"Lista original:\n";
a.printLinkedList();
cout<<"Lista: insertando el elemento 8 , 11 y 5:\n";
a.insertNode(8);
a.insertNode(11);
a.insertNode(5);
a.printLinkedList();
cout<<"Lista:eliminando el elemento 5 y 8:\n";
a.removeNode(1);
a.removeNode(5);
a.printLinkedList();
cout<<"Lista:eliminando 100\n";
a.removeNode(100);
a.printLinkedList();
}
