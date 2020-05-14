// Counting sort in C++ programming

#include <iostream>
using namespace std;

void countSort(int arr[], int n)
{

  int arr2[10];
  int index[10];//se crea una array donde se pondra cuantas veces un elemento se repite
  int max = arr[0];

  for (int i = 1; i < n; i++) //se busca en el arr cual es unmero mayor
    {
    if (arr[i] > max)
      max = arr[i];
  }


  for (int i = 0; i <= max; ++i) //los espacios de index se rellenan con 0
  {
    index[i] = 0;
  }


  for (int i = 0; i < n; i++)
  {
    index[arr[i]]++; //en index se procede a colocar las incidencias de los elementos
  }

  for (int i = 1; i <= max; i++)//se realize una suma consecutiva / acumulativa
  {
    index[i] += index[i - 1];
  }

  for (int i = n - 1; i >= 0; i--)
  {
    arr2[index[arr[i]] - 1] = arr[i]; //procede a ubicar ols elementos de arr en index y copiarlos en A2.
    index[arr[i]]--;                    //en index disminuye en uno el contenido en el cual ha consultado arr
  }

  for (int i = 0; i < n; i++)   //se copian los elementos de Arr2 (ya estan ordenados) en Arr
  {
    arr[i] = arr2[i];
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}


int main()
{
  int arr[] = {4, 2, 2, 8, 3, 3, 1};
  int n = 7;
  cout << "Counting Sort\n\nArray desordenada: \n";
  printArray(arr, n);
  countSort(arr, n);
  cout << "\nArray ordenada: \n";
  printArray(arr, n);
}
