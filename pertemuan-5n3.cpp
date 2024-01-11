#include <iostream>
#include <string>

using namespace std;

// Definisi struktur Node untuk Double Linked List
struct Mahasiswa
{
    string nrp;
    string nama;
    string kelas;
    Mahasiswa *prev;
    Mahasiswa *next;
};

// Definisi kelas DoubleLinkedList
class DoubleLinkedList
{
private:
    Mahasiswa *head;
    Mahasiswa *tail;

public:
    // Konstruktor
    DoubleLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Cek apakah Double Linked List kosong
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Sisipkan data mahasiswa secara terurut
    void sisipTerurut(string nrp, string nama, string kelas)
    {
        Mahasiswa *newNode = new Mahasiswa;
        newNode->nrp = nrp;
        newNode->nama = nama;
        newNode->kelas = kelas;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (isEmpty())
        {
            head = newNode;
            tail = newNode;
        }
        else if (nrp < head->nrp)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            Mahasiswa *current = head;
            while (current != nullptr && current->nrp < nrp)
            {
                current = current->next;
            }

            if (current == nullptr)
            {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            else if (current->nrp == nrp)
            {
                cout << "Data dengan NRP " << nrp << " sudah ada (duplikat)." << endl;
                delete newNode;
                return;
            }
            else
            {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }

        cout << "Data mahasiswa dengan NRP " << nrp << " berhasil disisipkan." << endl;
    }

    // Hapus data mahasiswa tertentu berdasarkan NRP
    void hapusData(string nrp)
    {
        if (isEmpty())
        {
            cout << "Double Linked List kosong. Tidak dapat melakukan penghapusan." << endl;
            return;
        }

        Mahasiswa *current = head;
        while (current != nullptr && current->nrp != nrp)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Data dengan NRP " << nrp << " tidak ditemukan." << endl;
            return;
        }

        if (current == head)
        {
            head = current->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            else
            {
                tail = nullptr;
            }
        }
        else if (current == tail)
        {
            tail = current->prev;
            tail->next = nullptr;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        cout << "Data mahasiswa dengan NRP " << nrp << " berhasil dihapus." << endl;
    }

    // Update data mahasiswa (nama dan kelas)
    void updateData(string nrp, string nama, string kelas)
    {
        if (isEmpty())
        {
            cout << "Double Linked List kosong. Tidak dapat melakukan update." << endl;
            return;
        }

        Mahasiswa *current = head;
        while (current != nullptr && current->nrp != nrp)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Data dengan NRP " << nrp << " tidak ditemukan." << endl;
            return;
        }

        current->nama = nama;
        current->kelas = kelas;

        cout << "Data mahasiswa dengan NRP " << nrp << " berhasil diupdate." << endl;
    }

    // Tampilkan isi Double Linked List dari depan ke belakang
    void displayForward()
    {
        if (isEmpty())
        {
            cout << "Double Linked List kosong." << endl;
        }
        else
        {
            cout << "Isi Double Linked List (dari depan ke belakang): " << endl;
            Mahasiswa *current = head;
            while (current != nullptr)
            {
                cout << "NRP: " << current->nrp << ", Nama: " << current->nama << ", Kelas: " << current->kelas << endl;
                current = current->next;
            }
        }
    }

    // Tampilkan isi Double Linked List dari belakang ke depan
    void displayBackward()
    {
        if (isEmpty())
        {
            cout << "Double Linked List kosong." << endl;
        }
        else
        {
            cout << "Isi Double Linked List (dari belakang ke depan): " << endl;
            Mahasiswa *current = tail;
            while (current != nullptr)
            {
                cout << "NRP: " << current->nrp << ", Nama: " << current->nama << ", Kelas: " << current->kelas << endl;
                current = current->prev;
            }
        }
    }
};

// Fungsi utama
int main()
{
    DoubleLinkedList mahasiswaList;
    int choice;
    string nrp, nama, kelas;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Sisipkan data mahasiswa" << endl;
        cout << "2. Hapus data mahasiswa" << endl;
        cout << "3. Update data mahasiswa" << endl;
        cout << "4. Tampilkan data mahasiswa (dari depan ke belakang)" << endl;
        cout << "5. Tampilkan data mahasiswa (dari belakang ke depan)" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan NRP: ";
            cin >> nrp;
            cout << "Masukkan Nama: ";
            cin >> nama;
            cout << "Masukkan Kelas: ";
            cin >> kelas;
            mahasiswaList.sisipTerurut(nrp, nama, kelas);
            break;
        case 2:
            cout << "Masukkan NRP data mahasiswa yang ingin dihapus: ";
            cin >> nrp;
            mahasiswaList.hapusData(nrp);
            break;
        case 3:
            cout << "Masukkan NRP data mahasiswa yang ingin diupdate: ";
            cin >> nrp;
            cout << "Masukkan Nama baru: ";
            cin >> nama;
            cout << "Masukkan Kelas baru: ";
            cin >> kelas;
            mahasiswaList.updateData(nrp, nama, kelas);
            break;
        case 4:
            mahasiswaList.displayForward();
            break;
        case 5:
            mahasiswaList.displayBackward();
            break;
        case 6:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}