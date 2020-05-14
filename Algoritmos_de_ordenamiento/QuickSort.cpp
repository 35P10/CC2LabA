#include <bits/stdc++.h>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index en el menor elemento

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot) //si se encunetra un elemento menor a pivor, este toma su lugar.
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high); //pi indica en que lugar es la particion

       //a las particiones se les aplicara quicksort
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n =6;
    cout << "QuickSort\n\nArray desordenada: \n";
    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "\nArray ordenada: \n";
    printArray(arr, n);
    return 0;
}
