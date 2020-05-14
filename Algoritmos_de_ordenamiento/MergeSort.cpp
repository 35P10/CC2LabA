#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];//se crean dos arrays vacias

    //se copia a las dos arrays vacias los elementos de arry
    for (i = 0; i < n1; i++)    //los elementos de arr se copian hasta n1
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)     //los elementos de arr se copian de n1 hasta n2
        R[j] = arr[m + 1+ j];



    i = 0; // inicial contador en la array L
    j = 0; // inicial contador en la array R
    k = l; // inicial contador en array principal arr.
    while (i < n1 && j < n2) //se comparan simultaneamente los ejementos de las arrays L y R
    {
        if (L[i] <= R[j])   //si L[i]e es menor que R[j], este se copia en la array principal arr
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];  //si no lo es, R[j] se copia en la array principal arr
            j++;
        }
        k++;
    }

    while (i < n1) //mientras i no se salga de la lista L
    {
        arr[k] = L[i];
        i++;
        k++;
    }


    while (j < n2) //mientras i no se salga de la lista L
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        //se divide el array en dos, m es el lugar donde se dara la division
        int m = l+(r-l)/2;

        // ordenar los dos divisiones
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = 6;

    cout << "Merge Sort\n\nArray desordenada: \n";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "\nArray ordenada: \n";
    printArray(arr, n);
    return 0;
}
