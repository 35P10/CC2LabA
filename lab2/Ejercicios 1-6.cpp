#include <iostream>

using namespace std;

//muestra una lista

int mostrar(int A[], int z)
{
    for (int i=0 ; i<z ; i++)
        cout<<A[i];
}

//ejercicio 1------------------

int sumadeelementos(int *A,int z)
{
    int suma=0;
    for (int i=0 ; i<z ; i++) //por cada elemento que recorre, el contador suma aumenta
        suma += *(A+i);
    return suma;
}

int sumadeelementos2(int A[],int z)
{
    if (z <= 0)
        return 0;
    return (sumadeelementos2 (A, z-1) + A[z-1]);
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

//ejercicio 3------------------

int cambiar(int A[], int a, int b)  //intercambia los elementos en la lista
{
    int c = A[a];
    A[a] = A[b];
    A[b] = c;
}

int copiararray(int A1[],int A2[],int z)    //copia los elementos de un array a otro
{
    for (int i=0 ; i<z ; i++)
        A2[i] = A1[i];
}

int comparar(int A1[],int A2[],int z)//si dos arrays son iguales
{
    for (int i=0 ; i<z ; i++)
        if (A2[i] != A1[i])
            return 0; //no son iguales
    return 1;
}


int ordenar(int A[], int z)
{
    int A2[z]; //se crea una lista, esta se usara para comparar los cambios en la lista A
    while (true)
    {
        if (comparar(A,A2,z)==1) //si la lista A2 es igual a la A, se rompre el ordenamiento
            break;              //siginifica que ya no hay nada mas que ordenar

        copiararray(A,A2,z);   //como no se sabe cuantas interaccion se dan para que se ordene
                            //cuando comienze la lista a repetirse, se determina que ya nada mas hay para ordenar
        for (int i=0 ; i<z-1 ; i++)
        {                           //el primer elemento se compara con el siguiente
            if (A[i]>A[i+1])        //y si este el mayor, se intercambia
                cambiar(A,i,i+1);   //esto ocurre indefinidamente
        }
    }
    mostrar(A,z);
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

//ejercicio 5------------------

char concatenar(char *A, char *B ,int sA)
{
    int sB=tamano(B);
    for (int i=0;i<sA;i++)  //a partir del espacio donde termina la
        *(B+i+sB)=*(A+i);   //cadena B se le aumenta los elementos de A
    cout<<B;
}

//ejercicio 6------------------

char copiarelementos(char *A, char *B ,int sA , int sB)
{
    for (int i=0;i<sB;i++)
    {
        if ((*(A+i)==NULL)&&(*(B+i)==NULL)) //si los espacios de ambas cadenas
            break;              //estan vacias, se rompen
        else if (*(A+i)==NULL)      //si la cadena A es mas corta, rellena
            *(B+i)=NULL;      //los espacios que sobran en la cadena B con Null
        else
            *(B+i)=*(A+i);  //copia el contenido en la casilla i de la cadena A
    }                          // a la casilla i del B
    cout<<B;
}

int main()
{
    int sizeA = 4;
    int A[sizeA]= {1,2,3,4};

    //ejercicio 1------------------

    //cout<<sumadeelementos( A,sizeA);
    //cout<<sumadeelementos2( A,sizeA);

    //ejercicio 2------------------

    //inverse(A,sizeA);
    //inverse2(A,0,sizeA);
    //mostrar(A,sizeA);

    //ejercicio 3------------------

    int sizeB = 4;
    int B[sizeB]= {4,3,2,1};

    //ordenar(B,sizeB);

    //ejercicio 4------------------

    char *S="Hola";
    //cout<<tamano(S);
    //cout<<tamano2(S,0);

    //------------------------------
    int sizeC = 20;
    char C[sizeC]= "LaComputacion";
    int sizeD = 20;
    char D[sizeD+sizeC]="CienciasDe";

    //ejercicio 5------------------

    //concatenar(C,D,sizeC);

    //ejercicio 6------------------

    //copiarelementos(C,D,sizeC,sizeD);

}
