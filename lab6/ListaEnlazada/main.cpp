#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

int main()
{
LinkedList a(6);
a.insertHead(7);
a.insertHead(9);
a.insertHead(1);

Iterator x = a.begin();

cout<<"Lista original:\n";

for(int i = 0; i<a.getSize() ; i++)
{

    cout<<*x<<" ";
    x++;
}

cout<<"Lista: insertando el elemento 8 y 5:\n";
a.insertHead(8);
a.insertTail(5);
cout<<"Lista: insertando el elemento2 :\n";
a.insertNodeC(2,7);
cout<<"Lista:eliminando el elemento 5 y 8:\n";
a.removeNode(8);
a.removeNode(5);
cout<<"Lista:eliminando 100\n";
a.removeNode(100);

x = a.begin();
for(int i = 0; i<a.getSize() ; i++)
{
    cout<<*x<<" ";
    x++;
}

}
