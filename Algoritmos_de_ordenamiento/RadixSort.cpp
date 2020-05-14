#include<iostream>
using namespace std;


int getMax(int arr[], int n) //funcion para encontrar el maximo valor
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}



void countSort(int arr[], int n, int exp)
{
    int arr2[n]; //se crea una lista
    int i, count[10] = {0};

    //almacena las recurrencias en arr
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    //Los elementos que se estan cambiando se editan en arr2
    for (i = n - 1; i >= 0; i--)
    {
        arr2[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }


    for (i = 0; i < n; i++) //copia en la array original (la principal) los elementos de arr2
        arr[i] = arr2[i];
}


void radixsort(int arr[], int n)
{
    int m = getMax(arr, n); //encuentra el mayor numero para extraer su numero de digitos

    //se ordena segun la posicion de digitos que se este comparando. exp= pow(10,i)
    //para acteder a los digitos
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout<< arr[i] << " ";
    cout<< endl;
}


int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;
    cout << "Radix Sort\n\nArray desordenada: \n";
    printArray(arr, n);
    radixsort(arr, n);
    cout << "\nArray ordenada: \n";
    printArray(arr, n);
    return 0;
}
