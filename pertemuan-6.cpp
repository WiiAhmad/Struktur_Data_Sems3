#include <iostream>
using namespace std;

// Fungsi untuk menulis angka dari n ke 0 dengan rekursi
void tulisAngkaMundur(int n)
{
    if (n >= 0)
    {
        cout << n << " ";
        tulisAngkaMundur(n - 1);
    }
}

// Fungsi untuk menulis angka dari 0 ke n dengan rekursi
void tulisAngkaMaju(int n)
{
    if (n >= 0)
    {
        tulisAngkaMaju(n - 1);
        cout << n << " ";
    }
}

// Fungsi rekursi untuk pengecekan keanggotaan elemen X dalam array a[n]
bool cekAnggota(int a[], int n, int X)
{
    if (n == 0)
    {
        return false;
    }
    if (a[n - 1] == X)
    {
        return true;
    }
    return cekAnggota(a, n - 1, X);
}

// Fungsi untuk pengecekan bilangan prima
bool cekBilanganPrima(int n, int i = 2)
{
    if (n <= 2)
    {
        return (n == 2) ? true : false;
    }
    if (n % i == 0)
    {
        return false;
    }
    if (i * i > n)
    {
        return true;
    }
    return cekBilanganPrima(n, i + 1);
}

int main()
{
    int n;

    // Tes fungsi tulisAngkaMundur
    cout << "Masukkan nilai n: ";
    cin >> n;
    cout << "Hasil tulisAngkaMundur: ";
    tulisAngkaMundur(n);
    cout << endl;

    // Tes fungsi tulisAngkaMaju
    cout << "Hasil tulisAngkaMaju: ";
    tulisAngkaMaju(n);
    cout << endl;

    // Tes fungsi cekAnggota
    int arr[] = {1, 2, 3, 4, 5};
    int X;
    cout << "Masukkan angka yang ingin dicek: ";
    cin >> X;
    bool anggota = cekAnggota(arr, sizeof(arr) / sizeof(arr[0]), X);
    if (anggota)
    {
        cout << "Angka " << X << " merupakan anggota dari array." << endl;
    }
    else
    {
        cout << "Angka " << X << " bukan merupakan anggota dari array." << endl;
    }

    // Tes fungsi cekBilanganPrima
    cout << "Masukkan angka yang ingin dicek: ";
    cin >> n;
    bool prima = cekBilanganPrima(n);
    if (prima)
    {
        cout << n << " adalah bilangan prima." << endl;
    }
    else
    {
        cout << n << " bukan bilangan prima." << endl;
    }

    return 0;
}