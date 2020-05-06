#include <iostream>

using namespace std;

//muestra una lista

int mostrar(int A[], int z)
{
    for (int i=0 ; i<z ; i++)
        cout<<A[i];
}


//ejercicio 4------------------

int tamano(char *A)
{
    int i=0;
    while (*(A+i)!=NULL) //mientrar no haya NULL(nada) (osea mientras ese espacio contenga un elemento)
        i++;               // el contador i recorrera los espacios y se incrementa en
    return i;
}

int tamano2(char *A,int i)
{
    if (*(A+i)==NULL)
        return 0;
    return (tamano2(A,i+1)+1);
}


int main()
{
    //ejercicio 4------------------

    char *S="Hola";
    cout<<tamano(S);
    cout<<tamano2(S,0);

}
