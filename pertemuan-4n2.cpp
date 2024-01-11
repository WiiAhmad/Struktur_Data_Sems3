#include <iostream>

using namespace std;

// Definisi struktur Node untuk Linked List
struct Node {
    int data;
    Node* next;
};

// Definisi kelas Stack
class Stack {
private:
    Node* top;

public:
    // Konstruktor
    Stack() {
        top = nullptr;
    }

    // Destructor
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Push elemen ke Stack
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Elemen " << value << " berhasil ditambahkan ke dalam Stack." << endl;
    }

    // Pop elemen dari Stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong. Tidak dapat melakukan pop." << endl;
        } else {
            Node* temp = top;
            top = top->next;
            int poppedValue = temp->data;
            delete temp;
            cout << "Elemen " << poppedValue << " berhasil dihapus dari Stack." << endl;
        }
    }

    // Cek apakah Stack kosong
    bool isEmpty() {
        return top == nullptr;
    }

    // Tampilkan isi Stack
    void display() {
        if (isEmpty()) {
            cout << "Stack kosong." << endl;
        } else {
            cout << "Isi Stack: ";
            Node* current = top;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

// Fungsi utama
int main() {
    Stack stack;
    int choice, value;

    do {
        cout << "Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan Stack" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan elemen yang ingin ditambahkan: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}