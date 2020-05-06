#include <iostream>

using namespace std;

int mostrar(int A[], int z)
{
    for (int i=0 ; i<z ; i++)
        cout<<A[i];
}


//ejercicio 2------------------

int inverse (int A[], int z)
{
    int j=z-1,b;                  //j es el tamano de la lista
    for (int i=0 ; i<z/2 ; i++)   //se divide la lista a la mitad
    {
        b=A[i];                  //los extremos se intercambian
        A[i]=A[j];
        A[j]=b;
        j--;                       //i aumenta y j disminuye
    }
    return mostrar(A,z);
}

int inverse2 (int A[], int a, int z)
{
    if (a>z/2)
        return 0;
    int b=A[a];
    A[a]=A[z-1];
    A[z-1]=b;
    return (inverse2(A,a+1,z-1));
}


int main()
{
    int sizeA = 4;
    int A[sizeA]= {1,2,3,4};

    //ejercicio 2------------------

    inverse(A,sizeA);
    inverse2(A,0,sizeA);


}
