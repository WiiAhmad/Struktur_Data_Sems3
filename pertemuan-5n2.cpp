#include <iostream>

using namespace std;

// Definisi struktur Node untuk Double Linked List
struct Node
{
    int data;
    Node *prev;
    Node *next;
};

// Definisi kelas Queue
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    // Konstruktor
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Cek apakah Queue kosong
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Enqueue (menambahkan elemen ke dalam Queue)
    void enqueue(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        cout << "Elemen " << data << " berhasil ditambahkan ke dalam Queue." << endl;
    }

    // Dequeue (menghapus elemen dari Queue)
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue kosong. Tidak dapat melakukan dequeue." << endl;
            return;
        }

        Node *temp = rear;
        rear = rear->prev;

        if (rear != nullptr)
        {
            rear->next = nullptr;
        }
        else
        {
            front = nullptr;
        }

        int data = temp->data;
        delete temp;

        cout << "Elemen " << data << " berhasil dihapus dari Queue." << endl;
    }

    // Tampil (menampilkan isi Queue)
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue kosong." << endl;
        }
        else
        {
            cout << "Isi Queue: ";
            Node *current = front;
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

// Fungsi utama
int main()
{
    Queue queue;
    int choice, data;

    do
    {
        cout << "Menu:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Tampil" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Masukkan elemen yang ingin ditambahkan: ";
            cin >> data;
            queue.enqueue(data);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.display();
            break;
        case 4:
            cout << "Terima kasih!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}