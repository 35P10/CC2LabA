#include <iostream>

using namespace std;

//muestra una lista

int mostrar(int A[], int z)
{
    for (int i=0 ; i<z ; i++)
        cout<<A[i];
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

int main()
{

    //ejercicio 3------------------

    int sizeB = 4;
    int B[sizeB]= {4,3,2,1};

    ordenar(B,sizeB);

}
