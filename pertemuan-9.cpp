#include <iostream>
using namespace std;

// Fungsi untuk menggabungkan dua bagian terurut dari array
void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Buat array sementara untuk menyimpan bagian kiri dan kanan
    int L[n1], R[n2];

    // Salin data ke array sementara
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Gabungkan kembali array sementara ke array asli dengan membandingkan elemen-elemennya
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Salin sisa elemen jika ada
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Algoritma Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        // Bagi array menjadi dua bagian dan panggil mergeSort rekursif untuk setiap bagian
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Gabungkan dua bagian terurut
        merge(arr, left, middle, right);
    }
}

// Fungsi untuk memilih pivot dan membagi array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Pilih elemen terakhir sebagai pivot
    int i = (low - 1);     // Indeks elemen yang lebih kecil

    for (int j = low; j <= high - 1; j++)
    {
        // Jika elemen saat ini lebih kecil atau sama dengan pivot
        if (arr[j] <= pivot)
        {
            i++; // Pindahkan elemen yang lebih kecil ke sebelumnya
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Algoritma Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partition index, array akan dipecah di sekitar index ini
        int pi = partition(arr, low, high);

        // Panggil quickSort rekursif untuk dua bagian sebelum dan setelah partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    cout << "Hasil Merge Sort: ";
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    cout << "Hasil Quick Sort: ";
    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}