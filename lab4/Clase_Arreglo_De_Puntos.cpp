#include <iostream>
using namespace std;

class Punto
{
private:
    int x;
	int y;
public:
    Punto();
    Punto(int new_x, int new_y);
    int getX() const;
    int getY() const;
    void setX(const int nuevo_x);
    void setY(const int nuevo_y);

    void printPunto();
};


Punto::Punto()
{
    x=0;
    y=0;
}

Punto::Punto(int new_x, int new_y)
{
    x=new_x;
    y=new_y;
}

int Punto::getX() const
{
    return x;
}

int Punto::getY() const
{
    return y;
}

void Punto::setX(const int nuevo_x)
{
    x=nuevo_x;
}

void Punto::setY(const int nuevo_y)
{
    y=nuevo_y;
}

void Punto::printPunto()
{
    cout << "(" << x << "," << y << ")";
}

/*
. Implementa la clase ArregloDePuntos la cual representará un arreglo dinámico de Punto. Este arreglo debe
redimensionar dinámicamente su tamaño.

• La clase debe tener como varibles miembro privadas: un puntero de tipo Punto y un entero para el tamaño del
arreglo.
• Contructores

    – Contructor para inicializar los elementos del arreglo
        ArregloDePuntos::ArregloDePuntos(const Punto puntos[], const int tam)

    – Constructor copia
        ArregloDePuntos::ArregloDePuntos(const ArregloDePuntos &o)

    – Destructor
        ArregloDePuntos::~ArregloDePuntos()

*/

class ArregloDePuntos
{
private:
    Punto *Puntos;
    int tam;
public:
   ArregloDePuntos(const Punto puntos[], const int tam);
   ArregloDePuntos(const ArregloDePuntos &o);
   ~ArregloDePuntos();

   void redimensionar(int n); ///Debe implementar una función para redimensionar el tamaño el arreglo dinámicamente

   void pushback(const Punto &p); ///Adicionar un Punto al final del arreglo:
   void insert(const int posicion, const Punto &p); ///Insertar un Punto en cualquier posición del arreglo:
   void remove(const int pos);  ///Eliminar un Punto de cualquier posición del arreglo:
   const int getSize() const; ///Obtener el tamaño del arreglo
   void clear(); ///Eliminar todos los elementos del arreglo

   void printArregloDePuntos();
};

ArregloDePuntos::ArregloDePuntos(const Punto puntos[], const int tamanio)
{
    Puntos = new Punto [tamanio];
    for (int i=0 ; i<tamanio ; i++)
        Puntos[i] = puntos[i];
    tam = tamanio;

}

ArregloDePuntos::ArregloDePuntos(const ArregloDePuntos &o)
{
    Puntos = o.Puntos;
    tam= o.tam;
}

ArregloDePuntos::~ArregloDePuntos()
{
    delete []Puntos;
}

void ArregloDePuntos::redimensionar(int n)
{
    Punto *new_Puntos = new Punto[n];

    if (n>tam) //si la nueva dimension es mayor al tamaño original
    {
        for (int i = 0; i < tam; i++)
            new_Puntos[i] = Puntos[i];
        new_Puntos[n-1]= Punto();
    }
    else //si la nueva dimension es menor al tamaño original
    {
        for (int i = 0; i < n; i++)
            new_Puntos[i] = Puntos[i];
    }
    tam = n;
    delete []Puntos;
    Puntos = new_Puntos;
}


void ArregloDePuntos::pushback(const Punto &p)
{
    redimensionar(tam+1);
    Puntos[tam-1] = p;
}

void ArregloDePuntos::insert(const int posicion, const Punto &p)
{
    if (posicion<=tam){
        redimensionar(tam+1);
        for (int i=tam-1 ; i>posicion ;i--)
            Puntos[i]=Puntos[i-1];
        Puntos[posicion] = p;
    }
    else
        cout <<"\nPosicion no valida\n";
}

void ArregloDePuntos::remove(const int pos)
{
    if (pos<=tam){
        for (int i=pos ; i<tam-1 ;i++)
            Puntos[i]=Puntos[i+1];
        redimensionar(tam-1);
    }
    else
        cout <<"\nPosicion no valida\n";
}

const int ArregloDePuntos::getSize() const
{
    return tam;
}
void ArregloDePuntos::clear()
{
    delete []Puntos;
    cout<<"Elementos eliminados"<<endl;
    //for (int i=0 ; i<tam ;i++)
    //    Puntos[i]=Punto();
}

void ArregloDePuntos::printArregloDePuntos()
{
    for (int i=0 ; i<tam ;i++){
        Puntos[i].printPunto();
        if (i != tam - 1)
            cout << " , ";
    }
}

int main()
{
    while (true)
    {
       int tamano,x,y,op,p;
        cout << "======Arreglo de punteros======\n\nIngrese el tamano del arreglo"<<endl;
        cin>>tamano;
        cout << "\nIngrese X y Y , ejemplo : 8 9 "<<endl;
        Punto Array [tamano];
        for (int i=0; i<tamano ; i++)
        {
            cout << "Punto "<<i+1<<": ";
            cin>>x>>y;
            Punto a(x,y);
            Array[i] = a;
        }
        cout << "\nArreglo creado\n"<<endl;

        ArregloDePuntos A(Array , tamano);
        A.printArregloDePuntos();

        while(true)
        {
            cout<<"\n\n=====Acciones=====\n\n1)Anadir un punto al final\n2)Insertar un punto en medio\n3)Eliminar un punto\n4)Consultar tamanio\n5)Limpiar elementos\n0)Salir\n\nIngrese la opcion: ";
            cin>>op;
             cout<<"\n==================\n\n";
            if (op == 1)
            {
                cout <<"Punto que desea añadir: ";
                cin>>x>>y;
                Punto a(x,y);
                A.pushback(a);
            }
            else if (op == 2)
            {
                cout <<"El tamaño del arreglo es: "<<A.getSize()<<endl;
                cout <<"Anadir un punto el la posicion: ";
                cin>>p;
                cout << "\nPunto: ";
                cin>>x>>y;
                Punto a(x,y);
                A.insert(p,a);
            }
            else if (op == 3)
            {
                cout <<"El tamaño del arreglo es: "<<A.getSize()<<endl;
                cout <<"Eliminar posicion: ";
                cin>>p;
                A.remove(p);
            }
            else if (op == 4)
            {
                cout <<"El tamaño del arreglo es: "<<A.getSize()<<endl;

            }
            else if (op == 5)
            {
                A.clear();
                break;
            }
            else if (op == 0)
            {
                break;
            }
            else
            {
                cout <<"Opcion incorrecta!\nIngrese una opcion valida :D\n\n";
            }
            cout<<"\n=====Arreglo Actualizado=====\n"<<endl;
            A.printArregloDePuntos();
        }
        cout<<"\nDesea salir?\n0)Si\n1)No\n";
        cin>>op;
        if (op==0)
            break;
        else if (op==1)
            cout<<"\n:D\n";
        else
            cout<<"\nNo puso 0, asi que continua (:\n";

    }



/*
    Punto a(1,3);
    Punto b(2,4);
    Punto c(3,8);
    Punto d(4,7);

    int tamano = 2;
    Punto Array [tamano] = {a, b};

    ArregloDePuntos A(Array , tamano);
    cout << "Original"<<endl;
    A.printArregloDePuntos();

    cout<<endl<< "Add"<<endl;
    A.pushback(c);
    A.printArregloDePuntos();

    cout<<endl<< "AddMedio"<<endl;
    A.insert(1,d);
    A.printArregloDePuntos();

    cout<<endl<< "borrar"<<endl;
    A.remove(2);
    A.printArregloDePuntos();

    cout<<endl<< "clean"<<endl;
    A.clear();
    A.printArregloDePuntos();*/

}
