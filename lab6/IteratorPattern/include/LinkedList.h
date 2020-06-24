#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include "Iterator.h"
using namespace std;

template<typename T>
class LinkedList
{
private:
        Node<T> *head;
        Node<T> *tail;
        int size;
public:
        LinkedList(){
        size = 0;
        head = NULL;
        tail = NULL;
        cout<<"\nLinkedList vacia creada\n";
        }

        LinkedList(T x){
        size = 1;
        head = new Node<T>(x);
        cout<<"\nLinkedList con head creada\n";
        }

        void insertHead(T x){
        Node<T> *New_node = new Node<T>(x);
        if (head==NULL){
            head = New_node;
        }
        else{
            New_node->next=head;
            head = New_node;
            //cout<<"Head reasignado\n";
        }
        size++;
        }

        void insertTail(int x){
        Node<T> *cont = head;
        Node<T> *New_node = new Node<T>(x);
        if (head==NULL){
        head = New_node;
        }
        else{
        while((cont->next!=NULL)){
            cont = cont->next;
        }
        cont->next = New_node;
        tail = New_node;
        }
        size++;
        }

        void insertNode(T x,int j){
        Node<T> *cont = head;
        Node<T> *New_node = new Node<T>(x);
        if (j==1){
            insertHead(x);
        }
        else if (j==size){
            insertTail(x);
        }
        else if (j>size){
        cout<<"\nEl lugar donde se quiere insertar sobrepasa al tamano de lista\n";
        }
        else{
        for(int i=2;i<j;i++){
            cont = cont->next;
        }
        New_node->next = cont->next;
        cont->next = New_node;
        size++;
        }
        }

        void removeNode(T x){
        Node<T> *cont = head;
        Node<T>  *cont2 = head->next;
        if(head->x==x){
        head= cont->next;
        cout<<"\nHead eliminado\n";
        }
        else{
        while (cont2!=NULL){
        if (cont2->x == x){
            cont->next = cont2->next;
            break;
        }
        else{
        cont = cont->next;
        cont2 = cont2->next;
        }
        }
        size--;
        }
        if (cont2==NULL)
        cout<<"\nElemento no encontrado\n";
        }

        Iterator<T> begin(){
            return Iterator<T>(head);
        }

        Iterator<T> end(){
            return Iterator<T>(tail);
        }

        int getSize()
        {
            return size;
        }
};

#endif // LINKEDLIST_H
