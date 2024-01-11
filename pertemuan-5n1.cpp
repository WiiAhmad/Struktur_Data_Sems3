#include <iostream>

using namespace std;

// Definisi struktur Node untuk Double Linked List
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Definisi kelas DoubleLinkedList
class DoubleLinkedList {
private:
    Node* head;
    Node* tail;

public:
    // Konstruktor
    DoubleLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Cek apakah Double Linked List kosong
    bool isEmpty() {
        return head == nullptr;
    }

    // Sisipkan data secara terurut
    void sisipTerurut(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (isEmpty()) {
            head = newNode;
            tail = newNode;
        } else if (data < head->data) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            Node* current = head;
            while (current != nullptr && current->data < data) {
                current = current->next;
            }

            if (current == nullptr) {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            } else if (current->data == data) {
                cout << "Simpul dengan data " << data << " sudah ada (duplikat)." << endl;
                delete newNode;
                return;
            } else {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }

        cout << "Simpul dengan data " << data << " berhasil disisipkan." << endl;
    }

    // Hapus simpul tertentu berdasarkan data
    void hapusSimpul(int data) {
        if (isEmpty()) {
            cout << "Double Linked List kosong. Tidak dapat melakukan penghapusan." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr && current->data != data) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Simpul dengan data " << data << " tidak ditemukan." << endl;
            return;
        }

        if (current == head) {
            head = current->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
        } else if (current == tail) {
            tail = current->prev;
            tail->next = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;
        cout << "Simpul dengan data " << data << " berhasil dihapus." << endl;
    }

    // Tampilkan isi Double Linked List dari depan ke belakang
    void displayForward() {
        if (isEmpty()) {
            cout << "Double Linked List kosong." << endl;
        } else {
            cout << "Isi Double Linked List (dari depan ke belakang): ";
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    // Tampilkan isi Double Linked List dari belakang ke depan
    void displayBackward() {
        if (isEmpty()) {
            cout << "Double Linked List kosong." << endl;
        } else {
            cout << "Isi Double Linked List (dari belakang ke depan): ";
            Node* current = tail;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->prev;
            }
            cout << endl;
        }
    }
};

// Fungsi utama
int main(){
    DoubleLinkedList dll;
    int pilihan, data;

    do {
        cout << "1. Sisipkan data secara terurut" << endl;
        cout << "2. Hapus simpul tertentu" << endl;
        cout << "3. Tampilkan isi Double Linked List dari depan ke belakang" << endl;
        cout << "4. Tampilkan isi Double Linked List dari belakang ke depan" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Data yang akan disisipkan: ";
                cin >> data;
                dll.sisipTerurut(data);
                break;
            case 2:
                cout << "Data yang akan dihapus: ";
                cin >> data;
                dll.hapusSimpul(data);
                break;
            case 3:
                dll.displayForward();
                break;
            case 4:
                dll.displayBackward();
                break;
            case 5:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan salah." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
        
