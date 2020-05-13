#include <iostream>

using namespace std;


int tamano(char *A)
{
    int i=0;
    while (*A++!=NULL) //mientrar no haya NULL(nada) (osea mientras ese espacio contenga un elemento)
        i++;               // el contador i recorrera los espacios y se incrementa en
    return i;
}

//ejercicio 5------------------

char concatenar(char *A, char *B ,int sA)
{
    int sB=tamano(B);
    for (int i=0;i<sA;i++)  //a partir del espacio donde termina la
        *(B+i+sB)=*(A+i);   //cadena B se le aumenta los elementos de A
    cout<<B;
}

int main()
{
    int sizeC = 20;
    char C[sizeC]= "LaComputacion";
    int sizeD = 20;
    char D[sizeD+sizeC]="CienciasDe";

    concatenar(C,D,sizeC);

}
