#include <iostream>

using namespace std;

struct Mahasiswa
{
    int NIM;
    string nama;
    string jurusan;
    float IPK;
};
Mahasiswa mhs;

int main()
{

    mhs.NIM = 12345;
    mhs.nama = "Fulan";
    mhs.jurusan = "Teknik Informatika";
    mhs.IPK = 3.5;

    cout << "NIM: " << mhs.NIM << endl;
    cout << "Nama: " << mhs.nama << endl;
    cout << "Jurusan: " << mhs.jurusan << endl;
    cout << "IPK: " << mhs.IPK << endl;

    int array[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++)
    {
        cout << "Nilai array ke-" << i << " adalah " << array[i] << endl;
    }

    int variabel = 10;
    int *ptr = &variabel;

    cout << "Nilai variabel: " << variabel << endl;
    cout << "Alamat variabel: " << &variabel << endl;
}