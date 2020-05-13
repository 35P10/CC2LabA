#include <iostream>

using namespace std;


//ejercicio 4------------------

int tamano(char *A)
{
    int i=0;
    while (*A++!=NULL)
        i++;
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
    cout<<tamano(S)<<endl;
    cout<<tamano2(S,0);

}
