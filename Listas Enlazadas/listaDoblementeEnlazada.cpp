#include <iostream>
#include <ctime>
#include <bits/stdc++.h> 
using namespace std;
template <typename T> class Node;
template <typename T> class LinkedList;

template <typename T>
class Node
{
private:
    T x;
	Node<T> *next;
    Node<T> *prev;
public:
    Node(T new_data);
    ~Node();
    T getData();
    void Delete_this();
    void Printnode();

    friend class LinkedList<T>;
};

template <class T>
Node<T>:: Node(T new_data){
    x = new_data;
    next = NULL;
    prev = NULL;
}

template <class T>
Node<T>:: ~Node(){

}

template <class T>
T Node<T>::getData(){
    return x;
}

template <class T>
void Node<T>::Delete_this(){
    if (next)
        next->Delete_this();
    delete this;
} 

template <class T>
void Node<T>::Printnode(){
    if(next!=NULL)
            cout<<x<<"<->";
        else
            cout<<x<<",  ";
} 
    

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    LinkedList(T x);
    int getSize();
    void insertar(T valor,int posicion);
    void remover(int posicion);
    int buscar(T valor);
    void printLinkedList();

};

template <class T>
LinkedList<T>:: LinkedList(T x){
    size = 1;
    head = new Node<T>(x);
    tail = new Node<T>(x);
}

template <class T>
int LinkedList<T>::getSize(){
    return size;
}

template <class T>
void LinkedList<T>::insertar(T valor,int posicion){
    Node<T> *cont = head;
    Node<T> *New_node = new Node<T>(valor);

    if(posicion>=-1){
    if (head==NULL || posicion == 0)
    {
        New_node->next= head;
        head->prev=New_node;
        head = New_node;
    
    }
    else if (posicion >= size || posicion ==-1)
    {
        while(cont->next!=NULL)
            cont = cont->next;
        cont->next=New_node;
        New_node->prev=cont;
        tail=New_node;
    }
    else
    {
        for(int i=1 ; i<posicion ; i++){
            cont=cont->next;
        }
        New_node->prev=cont;
        New_node->next=cont->next;
        New_node->next->prev=New_node;
        cont->next=New_node;
    }
    size++;
    }
}


template <class T>
void LinkedList<T>::remover(int posicion)
 {
    if(posicion<size && posicion>=0){
    if(posicion==0)
    {
        head= head->next;
        delete head->prev;
        head->prev = NULL;
        cout<<"Head removido\n";
    }
    else if(posicion==size-1)
    {
        tail=tail->prev;
        delete tail->next;
        tail->next=NULL;
        cout<<"Tail removida\n";
    }
    else
    {
        Node<T> *cont = head;
        for (int i=0 ;i!=posicion;i++){
            cont = cont->next;
        }
        cont->next->prev=cont->prev;
        cont->prev->next=cont->next;
        delete cont;    
    }
    size--;
    }
}

template <class T>
int LinkedList<T>:: buscar(T valor)
 {
    int cont=0;
    Node<T> *temp = head;
    while (temp != NULL){
        if (temp->x==valor)
            return cont;
        else{
            temp = temp->next;
            cont++;
        }
    }
    return -1;
}

template <class T>
void LinkedList<T>::printLinkedList()
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
        Node<T> *i = head;
        while(i!=NULL)
        {
            i->Printnode();
            i=i->next;
        }
        cout<<"Tamaño: "<<size<<" Head: "<<head->x<<" Tail: "<<tail->x<<endl;
    }
}


template <class T>
void nose(LinkedList<T>&L,int x)
{
    srand((unsigned) time(0));
    int randomNumber;
    for(int i=0 ; i<x ; i++){
        randomNumber = (rand() % 35) + 0;
        L.insertar(randomNumber,-1);
    }
}

template <class T>
void pruebac(LinkedList<T>&L,int x)
{
    srand((unsigned) time(0));
    int randomNumber;
    int randomNumber2;
    for(int i=0 ; i<x ; i++){
        randomNumber = (rand() % 100) + 0;
        randomNumber2 = (rand() % L.getSize()) + 0;
        L.insertar(randomNumber,randomNumber2);
    }
}

template <class T>
void pruebaf(LinkedList<T>&L,int x)
{
    if(x<=L.getSize()){
        srand((unsigned) time(0));
        int randomNumber;
        for(int i=0 ; i<x ; i++){
            randomNumber = (rand() % L.getSize()) + 0;
            L.remover(randomNumber);
        }
    }
    else
    {
        cout<<endl<<"No se pueden eliminar mas elementos de los que hay en la lista :)"<<endl;
    }
    
}

template <class T>
void pruebag(LinkedList<T>&L,int x)
{
    int cont=0;
    srand((unsigned) time(0));
    int randomNumber;
    for(int i=0 ; i<x ; i++){
        randomNumber = (rand() % 100) + 0;
        if(L.buscar(randomNumber)!=-1){
            cout<<randomNumber<<", ";
            cont++;
        }
    }    
    cout<<"Se encontraron: "<<cont<<" elementos."<<endl;
}



int main()
{
   clock_t start, end; 
    LinkedList<int> a(106);
    a.insertar(105,0);
    a.insertar(104,0);
    a.insertar(1000,0);
    a.insertar(100,0);
    a.printLinkedList();
    start = clock(); 
    cout<<endl<<"Lista Doblemente Enlazada: "<<endl;
    cout<<endl<<"Lista Inicial: "<<endl;
    a.printLinkedList();
    cout<<endl<<"Permitir que el usuario ingrese el número de elementos finales que tendrá la lista"<<endl;
    cout<<"y generarlos aleatoriamente (insertar cada nuevo elemento al final de la lista)."<<endl;
    nose<int>(a,10); //CAMBIE EL 10 POR CUALQUIER OTRO VALOR
    a.printLinkedList();
    cout<<endl<<"Pruebas: "<<endl;
    cout<<endl<<"a) Insertar al inicio "<<endl;
    a.insertar(103,0);
    a.printLinkedList();
    cout<<endl<<"b) Insertar al final "<<endl;
    a.insertar(125,a.getSize());
    a.printLinkedList();
    cout<<endl<<"c) Insertar 10 elementos aleatorios en 10 posiciones aleatorias del medio de las listas "<<endl;
    pruebac<int>(a,10);
    a.printLinkedList();
    cout<<endl<<"d) Remover el primer elemento"<<endl;
    a.remover(0);
    a.printLinkedList();
    cout<<endl<<"e) Remover el último elemento"<<endl;
    a.remover(a.getSize()-1); //comienza en posicion 0
    a.printLinkedList();
    cout<<endl<<"f) Remover 10 elementos en posiciones aleatorias del medio de las listas"<<endl;
    pruebaf<int>(a,10); 
    a.printLinkedList();
    cout<<endl<<"g) Buscar 100 valores aleatorios en las listas"<<endl; 
    pruebag<int>(a,100);
    a.printLinkedList();

    end = clock(); 
  

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 
    return 0; 
}