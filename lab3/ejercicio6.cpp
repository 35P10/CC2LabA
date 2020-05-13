#include <iostream>

using namespace std;

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
    int sizeC = 20;
    char C[sizeC]= "LaComputacion";
    int sizeD = 20;
    char D[sizeD+sizeC]="CienciasDe";

    copiarelementos(C,D,sizeC,sizeD);

}
