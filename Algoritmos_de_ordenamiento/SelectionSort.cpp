#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) //Recorre la lista desordenada
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;    //encuentra el minimo elemento

        swap(&arr[min_idx], &arr[i]); //intercambia el elemento minimo con el primero
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;
    cout << "Selection Sort\n\nArray desordenada: \n";
    printArray(arr, n);
    selectionSort(arr, n);
    cout << "\nArray ordenada: \n";
    printArray(arr, n);
    return 0;
}
