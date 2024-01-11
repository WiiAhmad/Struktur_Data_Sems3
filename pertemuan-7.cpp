#include <iostream>
using namespace std;

// Algoritma Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

// Algoritma Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {9, 1, 2, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Data awal: ";
    printArray(arr, n);

    cout << "Hasil Insertion Sort: ";
    insertionSort(arr, n);
    printArray(arr, n);

    cout << "Hasil Selection Sort: ";
    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}