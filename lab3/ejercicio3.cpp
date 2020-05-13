#include <iostream>

using namespace std;

//muestra una lista

int mostrar(int *A, int z)
{
    for (int i=0 ; i<z ; i++)
        cout<<*A++;
}


//ejercicio 3------------------

int cambiar(int *A, int a, int b)  //intercambia los elementos en la lista
{
    int c = *(A+a);
    *(A+a) = *(A+b);
    *(A+b) = c;
}

int copiararray(int *A1,int *A2,int z)    //copia los elementos de un array a otro
{
    for (int i=0 ; i<z ; i++)
        *(A2+i) = *(A1+i);
}

int comparar(int *A1,int *A2,int z)//si dos arrays son iguales
{
    for (int i=0 ; i<z ; i++)
        if (*(A2+i) != *(A1+i))
            return 0; //no son iguales
    return 1;
}


int ordenar(int *A, int z)
{
    int A2[z];
    while (true)
    {
        if (comparar(A,A2,z)==1)
            break;

        copiararray(A,A2,z);

        for (int i=0 ; i<z-1 ; i++)
        {
            if (*(A+i)>*(A+i+1))
                cambiar(A,i,i+1);
        }
    }
    mostrar(A,z);
}

int main()
{

    //ejercicio 3------------------

    int sizeB = 5;
    int B[sizeB]= {4,3,2,1,7};
    mostrar(B,sizeB);
    cout<<endl;
    ordenar(B,sizeB);

}
