#include <iostream>
#include <cmath>

using namespace std;

void decimalToBinary(int decimal, int binary[])
{
    int i = 0;
    while (decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
}

int binaryToDecimal(int binary[])
{
    int decimal = 0;
    int powerOfTwo = 1;
    for (int i = 0; i < 32; i++)
    {
        decimal += binary[i] * powerOfTwo;
        powerOfTwo *= 2;
    }
    return decimal;
}

int main()
{
    int bilangan, jumlahShift;

    // Input bilangan desimal dan jumlah shift
    cout << "Masukkan bilangan desimal: ";
    cin >> bilangan;

    cout << "Masukkan jumlah shift: ";
    cin >> jumlahShift;

    // Konversi bilangan desimal menjadi biner dengan menggunakan array
    int binary[32] = {0}; // Ukuran maksimum untuk integer 32-bit
    decimalToBinary(bilangan, binary);

    // Operasi shift left pada nilai biner yang ada di dalam array
    for (int i = 0; i < jumlahShift; i++)
    {
        for (int j = 31; j > 0; j--)
        {
            binary[j] = binary[j - 1];
        }
        binary[0] = 0; // Tambahkan bit kosong di bagian kanan setiap kali melakukan shift left
    }

    // Konversi kembali ke bentuk desimal dari nilai biner hasil operasi shift
    int shiftedDecimal = binaryToDecimal(binary);

    cout << "Bilangan setelah operasi shift: " << shiftedDecimal << endl;

    return 0;
}