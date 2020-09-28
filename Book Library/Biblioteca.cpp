#include <iostream>
#include <string>
using namespace std;
template <typename T> class Node;
template <typename T> class LinkedList;

template <typename T>
class Node
{
private:
    T x;
	Node<T> *next;
public:
    Node(T new_data);
    ~Node();
    T getData();
    void Delete_this();
    void Printnode();

    friend class LinkedList<T>;
    friend class Sistema;
    friend class Libro;
};

template <class T>
Node<T>:: Node(T new_data){
    x = new_data;
    next = NULL;
}

template <class T>
Node<T>:: ~Node(){
    delete next;
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
            cout<<x<<", ";
        else
            cout<<x<<".  ";
} 

//---------------------------------------------------------------------

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    int size;

public:
    LinkedList();
    LinkedList(T x);
    int getSize();
    void insertar(T x);
    void remover(int posicion);
    void printLinkedList();
    friend class Libro;
    friend class Sistema;
};

template <class T>
LinkedList<T>:: LinkedList(){
    size = 0;
    head = NULL;
}

template <class T>
LinkedList<T>:: LinkedList(T x){
    size = 1;
    head = new Node<T>(x);
}

template <class T>
int LinkedList<T>::getSize(){
    return size;
}

template <class T>
void LinkedList<T>::insertar(T x){
    Node<T> *New_node = new Node<T>(x);
    New_node->next= head;
    head = New_node;
    size++;
}

template <class T>
void LinkedList<T>::remover(int posicion){
    if(posicion>-1 && posicion<size){
        Node<T> *cont = head;
        Node<T> *cont2 = head->next; 
        if(posicion==0)
        {
            head= cont->next;
        }
        else
        {
            for (int i=0 ;i<posicion-1;i++){
                cont = cont->next;
                cont2 = cont2->next;
            }
            cont->next = cont2->next;
        }
        size--;
    }
}

template <class T>
void LinkedList<T>::printLinkedList(){
    if ((size==0)&&(head==NULL))
    {
        cout<<"\nLista Vacia\n";
    }
    else if ((size==1)&&(head!=NULL))
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
    }
}

//--------------------------------------------------------------------------

class Autor
{
private:
    string nombres;
    string apellidos;
public:
    Autor();
    Autor(string nombres,string apellidos);
    friend ostream& operator<<(ostream& os, const Autor& dt);
    bool operator==(const Autor& dt);
};

Autor::Autor()
{
    nombres="";
    apellidos="";
    
}

Autor::Autor(string nombres,string apellidos)
{
    this->nombres=nombres;
    this->apellidos=apellidos;
}

ostream& operator<<(ostream& os, const Autor& dt)
{
    os << dt.apellidos << " " << dt.nombres;
    return os;
}

bool Autor::operator==(const Autor& dt){
    if(nombres==dt.nombres && apellidos==dt.apellidos)
        return true;
    else
        return false;
}

//-------------------------------------------------------------------------

class Libro
{
private:
    int isbn;
    string titulo;
    int anio;
    string editorial;
    string resumen;
    LinkedList<Autor> autores;
public:
    Libro();
    Libro(int isbn,string titulo,int anio,string editorial,string resumen);
    void printLibro();
    void addAutores(string nombres,string apellidos);
    int buscarAutor(Autor temp0);
    friend ostream& operator<<(ostream& os, const Libro& dt);
    friend class Sistema;
};

Libro::Libro()
{
    
}

int Libro::buscarAutor(Autor temp0)
{
    Node<Autor> *temp = autores.head;
    while (temp!=NULL){
        if (temp->x==temp0){
            return 1;
        }
        else{
            temp = temp->next;
        }
    }
    return 0; 
}

Libro::Libro(int isbn,string titulo,int anio,string editorial,string resumen)
{
    this->isbn=isbn;
    this->titulo=titulo;
    this->anio=anio;
    this->editorial=editorial;
    this->resumen=resumen;
    //autores
    string i;
    string y;
    cout<<"Autor(es): "<<endl;
    while(true){
        cout<<"Nombres: ";
        getline(cin,i);
        cout<<"Apellidos: ";
        getline(cin,y);
        addAutores(i,y);
        cout<<"Desea agregar un autor mas?\n1 Si\n2 No\nOpcion a escoger(1 o 2): ";
        getline(cin,i);
        if(i!="1")
            break;
    }
}

void Libro::addAutores(string nombres,string apellidos)
{
    Autor x(nombres,apellidos);
    autores.insertar(x);
}

void Libro::printLibro()
{
    cout<<"\nISBN: "<<isbn<<endl;
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"Anio: "<<anio<<endl;
    cout<<"Editorial: "<<editorial<<endl;
    cout<<"Resumen: "<<resumen<<endl;
    cout<<"Autor(es): ";
    autores.printLinkedList();
    cout<<endl;
}

template<>
void Node<Libro>::Printnode(){
    x.printLibro();
} 

//---------------------------------------------------

class Sistema{
private:
    LinkedList<Libro> libros;
public:
    Sistema();
    void addLibro();
    void borrarLibro();
    int buscarLibroPorISBN(int isbn);
    int buscarLibroPorTitulo(string y);
    int buscarLibroPorAutor();
    void mostrarLibros();
};

Sistema::Sistema(){
    cout<<"=================================\nSistema De Libros Creado\n=================================\n";
}

void Sistema::addLibro()
{
    cout<<"\n---Agregar libro---\n";
    int isbn;
    string titulo;
    int anio;
    string editorial;
    string resumen;
    cout<<"ISBN:\n";
    cin>>isbn;
    if(buscarLibroPorISBN(isbn)==-1)
    {
    cin.get();
    cout<<"Titulo:\n";
    getline(cin,titulo);
    cout<<"Anio:\n";
    cin>>anio;
    cin.get();
    cout<<"Editorial:\n";
    getline(cin,editorial);
    cout<<"Resumen:\n";
    getline(cin,resumen);

    Node<Libro> *cont = libros.head;
    Node<Libro> *New_node = new Node<Libro>(Libro(isbn,titulo,anio,editorial,resumen));
    if (libros.head==NULL || libros.getSize()==0)
    {
        libros.head = New_node;
    }
    else
    {
        while(cont->next!=NULL)
            cont=cont->next;
        cont->next = New_node;
    } 
    libros.size++;
    cout<<"\n---Libro Agregado---\n";
    }
    else
    {
        cout<<"\nYa existe un libro con el ISBN "<<isbn<<endl;
    }
    
}

void Sistema::mostrarLibros()
{
    libros.printLinkedList();
    cout<<endl;
}

int Sistema::buscarLibroPorISBN(int isbn)
{
    int cont=0;
    Node<Libro> *temp = libros.head;
    while (temp != NULL){
        if (temp->x.isbn==isbn){
            temp->Printnode();
            return cont;
        }
        temp = temp->next;
        cont++;
    }
    return -1;
}

void Sistema::borrarLibro()
{
    int x;
    cout<<"\nEliminar por:\n1 ISBN\n2 Titulo\nElija opcion(1 o 2): ";
    cin>>x;
    if(x==1){
        cout<<"\nIngrese el ISBN del libro que desea borrar: ";
        int isbn;
        cin>>isbn;
        x=buscarLibroPorISBN(isbn);
        cout<<endl;
        if (x!=-1){
            libros.remover(x);
            cout<<"Libro Borrado\n";
        }
        else
            cout<<"Libro No Encontrado\n";
    }
    else if (x==2){
        cout<<"\nIngrese el titulo del libro que desea borrar: ";
        string y;
        cin.get();
        getline(cin,y);
        x=buscarLibroPorTitulo(y);
        cout<<endl;
        if (x!=-1){
            libros.remover(x);
            cout<<"Libro Borrado\n";
        }
        else
            cout<<"Libro No Encontrado\n";
    }
    else
        cout<<"Valor invalido";
}

int Sistema::buscarLibroPorAutor()  
{
    string nombre, apellido;
    cout<<"Nombres: ";
    cin.get();
    getline(cin,nombre);
    cout<<"Apellidos: ";
    getline(cin,apellido);
    Autor x(nombre,apellido);
    cout<<endl;
    int cont=0;
    Node<Libro> *temp = libros.head;
    while (temp != NULL){
        if (temp->x.buscarAutor(x)==1){
            temp->Printnode();
            cont++;
        }
        temp = temp->next;
    }
    return cont;
}

int Sistema::buscarLibroPorTitulo(string y)
{
    int cont=0;
    Node<Libro> *temp = libros.head;
    while (temp != NULL){
        if (temp->x.titulo==y){
            temp->Printnode();
            return cont;
        }
        temp = temp->next;
        cont++;
    }
    return -1;
}

//------------------------------------------

int main()
{
    int op=-1;
    Sistema libreria;
    while(op!=0){
        if(op==1){
            libreria.mostrarLibros();
            cout<<"\n=================================\n";
        }
        else if(op==2){
            libreria.addLibro();
            cout<<"\n=================================\n";
        }
        else if(op==3)
        {
            cout<<"\nISBN del libro que deseaa buscar: ";
            int isbn;
            cin>>isbn;
            if(libreria.buscarLibroPorISBN(isbn)==-1)
                 cout<<"\nNo se encontro coincidencia\n"; 
            cout<<"\n=================================\n";
        }
        else if(op==4)
        {
            cout<<"\nTitulo del libro que desea buscar: ";
            string y;
            cin.get();
            getline(cin,y);
            if(libreria.buscarLibroPorTitulo(y)==-1)
                cout<<"\nNo se encontro coincidencia\n"; 
            cout<<"\n=================================\n";
        }
        else if(op==5)
        {
            cout<<"\nBuscar por autor:\n";
            if(libreria.buscarLibroPorAutor()==0)
                cout<<"\nNo se encontro coincidencia\n"; 
            cout<<"\n=================================\n"; 
        }
        else if(op==6)
        {
            libreria.borrarLibro();
            cout<<"\n=================================\n"; 
        }
        cout<<"Acciones Disponibles:\n1 Listar Libros\n2 Agregar Libro\n3 Buscar Libro por ISBN\n4 Buscar libro por titulo\n5 Buscar libro por autor\n6 Eliminar Libro\n0 Salir\nElija opcion (1,2,3,4,5,6,0):";
        cin>>op;
    }

}