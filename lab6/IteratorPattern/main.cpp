#include <iostream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

int main()
{

    //Node<double> C(8.4);
    //C.Printnode();

    LinkedList<double> A(7);
    Iterator<double> it = A.begin();
    for(int i = 0; i<A.getSize() ; i++){
        cout<<*it<<" ";
        it++;
    }
    /////////////
    cout<<"\ninsertar head 8 , 7 , 6"<<endl;
    A.insertHead(8);
    A.insertHead(7);
    A.insertHead(6);
    it = A.begin();
    for(int i = 0; i<A.getSize() ; i++){
        cout<<*it<<" ";
        it++;
    }
    //////////////
    cout<<"\ninsertar tail 2"<<endl;;
    A.insertTail(2);
    it = A.begin();
    for(int i = 0; i<A.getSize() ; i++){
        cout<<*it<<" ";
        it++;
    }
    cout<<"\ninsertar 6 en posicion 5 "<<endl;;
    A.insertNode(6,5);
    it = A.begin();
    for(int i = 0; i<A.getSize() ; i++){
        cout<<*it<<" ";
        it++;
    }
    cout<<"\ninsertar 1 en posicion 2 "<<endl;;
    A.insertNode(1,2);
    it = A.begin();
    for(int i = 0; i<A.getSize() ; i++){
        cout<<*it<<" ";
        it++;
    }
    cout<<"\ninsertar 10 en posicion 100 ";
    A.insertNode(10,100);
    it = A.begin();
    for(int i = 0; i<A.getSize() ; i++){
        cout<<*it<<" ";
        it++;
    }

    return 0;
}
