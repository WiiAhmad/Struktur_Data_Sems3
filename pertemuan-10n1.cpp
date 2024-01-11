#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i; // Mengembalikan indeks elemen jika ditemukan
        }
    }
    return -1; // Mengembalikan -1 jika elemen tidak ditemukan
}

int main()
{
    int arr[] = {10, 1, 2, 11, 8, 7, 5, 4, 15, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    int result = sequentialSearch(arr, n, target);

    if (result == -1)
    {
        cout << "Data " << target << " tidak ditemukan." << endl;
    }
    else
    {
        cout << "Data " << target << " ditemukan pada indeks " << result << "." << endl;
    }

    return 0;
}