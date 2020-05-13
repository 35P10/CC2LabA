#include <iostream>

using namespace std;

//ejercicio 1------------------

int sumadeelementos(int *A,int z)
{
    int suma=0;
    for (int i=0 ; i<z ; i++)
        suma += *A++;
    return suma;
}

int sumadeelementos2(int *A,int z)
{
    if (z <= 0)
        return 0;
    return (sumadeelementos2 (A, z-1) + *(A+z-1));
}

int main()
{
    int sizeA = 4;
    int A[sizeA]= {1,2,3,4};

    //ejercicio 1------------------

    cout<<sumadeelementos( A,sizeA)<<endl;
    cout<<sumadeelementos2( A,sizeA);
}
