#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target)
{
    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (arr[middle] == target)
        {
            return middle; // Mengembalikan indeks elemen jika ditemukan
        }

        if (arr[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return -1; // Mengembalikan -1 jika elemen tidak ditemukan
}

int main()
{
    int arr[] = {2, 5, 6, 9, 10, 12, 15, 18, 20, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    int result = binarySearch(arr, 0, n - 1, target);

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