#include <iostream>
#include <string>

using namespace std;

// Definisi struktur Node untuk Linked List
struct Mahasiswa {
    int nrp;
    string nama;
    string kelas;
    Mahasiswa* next;
};

// Definisi kelas LinkedList
class LinkedList {
private:
    Mahasiswa* head;

public:
    // Konstruktor
    LinkedList() {
        head = nullptr;
    }

    // Destructor
    LinkedList() {
        while (!isEmpty()) {
            hapusDepan();
        }
    }

    // Cek apakah LinkedList kosong
    bool isEmpty() {
        return head == nullptr;
    }

    // Sisipkan data mahasiswa secara terurut
    void sisipTerurut(int nrp, string nama, string kelas) {
        Mahasiswa* newNode = new Mahasiswa;
        newNode->nrp = nrp;
        newNode->nama = nama;
        newNode->kelas = kelas;
        newNode->next = nullptr;

        if (isEmpty() || nrp < head->nrp) {
            newNode->next = head;
            head = newNode;
        } else {
            Mahasiswa* current = head;
            while (current->next != nullptr && current->next->nrp < nrp) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        cout << "Data mahasiswa dengan NRP " << nrp << " berhasil disisipkan." << endl;
    }

    // Hapus data mahasiswa tertentu berdasarkan NRP
    void hapusData(int nrp) {
        if (isEmpty()) {
            cout << "LinkedList kosong. Tidak dapat melakukan penghapusan." << endl;
        } else {
            Mahasiswa* current = head;
            Mahasiswa* prev = nullptr;
            bool found = false;

            while (current != nullptr) {
                if (current->nrp == nrp) {
                    found = true;
                    break;
                }
                prev = current;
                current = current->next;
            }

            if (found) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                cout << "Data mahasiswa dengan NRP " << nrp << " berhasil dihapus." << endl;
            } else {
                cout << "Data mahasiswa dengan NRP " << nrp << " tidak ditemukan." << endl;
            }
        }
    }

    // Update data mahasiswa (nama dan kelas) berdasarkan NRP
    void updateData(int nrp, string nama, string kelas) {
        if (isEmpty()) {
            cout << "LinkedList kosong. Tidak dapat melakukan update." << endl;
        } else {
            Mahasiswa* current = head;
            bool found = false;

            while (current != nullptr) {
                if (current->nrp == nrp) {
                    found = true;
                    break;
                }
                current = current->next;
            }

            if (found) {
                current->nama = nama;
                current->kelas = kelas;
                cout << "Data mahasiswa dengan NRP " << nrp << " berhasil diupdate." << endl;
            } else {
                cout << "Data mahasiswa dengan NRP " << nrp << " tidak ditemukan." << endl;
            }
        }
    }

    // Hapus data mahasiswa di depan LinkedList
    void hapusDepan() {
        if (isEmpty()) {
            cout << "LinkedList kosong. Tidak dapat melakukan penghapusan." << endl;
        } else {
            Mahasiswa* temp = head;
            head = head->next;
            delete temp;
            cout << "Data mahasiswa di depan LinkedList berhasil dihapus." << endl;
        }
    }

    // Tampilkan isi LinkedList
    void display() {
        if (isEmpty()) {
            cout << "LinkedList kosong." << endl;
        } else {
            cout << "Isi LinkedList: " << endl;
            Mahasiswa* current = head;
            while (current != nullptr) {
                cout << "NRP: " << current->nrp << ", Nama: " << current->nama << ", Kelas: " << current->kelas << endl;
                current = current->next;
            }
        }
    }
};

// Fungsi utama
int main() {
    LinkedList linkedList;
    int choice, nrp;
    string nama, kelas;

    do {
        cout << "Menu:" << endl;
        cout << "1. Sisipkan Data Mahasiswa" << endl;
        cout << "2. Hapus Data Mahasiswa" << endl;
        cout << "3. Update Data Mahasiswa" << endl;
        cout << "4. Tampilkan Data Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan NRP: ";
                cin >> nrp;
                cin.ignore();
                cout << "Masukkan Nama: ";
                getline(cin, nama);
                cout << "Masukkan Kelas: ";
                getline(cin, kelas);
                linkedList.sisipTerurut(nrp, nama, kelas);
                break;
            case 2:
                cout << "Masukkan NRP Mahasiswa yang akan dihapus: ";
                cin >> nrp;
                linkedList.hapusData(nrp);
                break;
            case 3:
                cout << "Masukkan NRP Mahasiswa yang akan diupdate: ";
                cin >> nrp;
                cin.ignore();
                cout << "Masukkan Nama Baru: ";
                getline(cin, nama);
                cout << "Masukkan Kelas Baru: ";
                getline(cin, kelas);
                linkedList.updateData(nrp, nama, kelas);
                break;
            case 4:
                linkedList.display();
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}