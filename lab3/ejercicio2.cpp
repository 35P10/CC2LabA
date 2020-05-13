#include <iostream>

using namespace std;

void mostrar(int *A, int z)
{
    for (int i=0 ; i<z ; i++)
        cout<<*A++;
}

int cambiar(int *A, int a, int b)
{
    int c = *(A+a);
    *(A+a) = *(A+b);
    *(A+b) = c;
}


//ejercicio 2------------------

void inverse (int *A, int z)
{
    int j=z-1;
    for (int i=0 ; i<j ; i++,j--)
    {
        cambiar(A,i,j);
    }
     mostrar(A,z);
}

void inverse2 (int *A, int a, int z)
{
    if (a>z/2)
        return;
    cambiar(A,a,z-1);
    inverse2(A,a+1,z-1);
}


int main()
{
    int sizeA = 5;
    int A[sizeA]= {1,2,3,4,5};

    //ejercicio 2------------------

    mostrar(A,sizeA);
    cout<<endl;
    inverse(A,sizeA);
    cout<<endl;
    inverse2(A,0,sizeA);
    mostrar(A,sizeA);






}
