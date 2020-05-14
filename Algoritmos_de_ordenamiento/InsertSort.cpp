// C++ program for insertion sort
#include <bits/stdc++.h>
using namespace std;


void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) //recorre toda la lista desde la posicion 1
    {
        key = arr[i];
        j = i - 1;


        while (j >= 0 && arr[j] > key)  //key se ubica en la array, recorriendola hacia la izquierda, si es mayor que el elemento adyacente izquierdo, ahi se ubica
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = 5;
    cout << "Insert Sort\n\nArray desordenada: \n";
    printArray(arr, n);
    insertionSort(arr, n);
    cout << "\nArray ordenada: \n";
    printArray(arr, n);

    return 0;
}
