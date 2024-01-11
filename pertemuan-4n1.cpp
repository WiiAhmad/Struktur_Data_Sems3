#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void addHead(int data)
    {
        if (contains(data))
        {
            cout << "Data is duplicate" << endl;
            return;
        }
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
        if (tail == NULL)
        {
            tail = head;
        }
    }

    void addTail(int data)
    {
        if (contains(data))
        {
            cout << "Data is duplicate" << endl;
            return;
        }
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool contains(int data)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void deleteHead() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) {
            tail = NULL;
        }
    }

    void deleteTail() {
        if (tail == NULL) {
            return;
        }
        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void deleteMiddle(int data) {
        if (head == NULL) {
            return;
        }
        if (head->data == data) {
            deleteHead();
            return;
        }
        if (tail->data == data) {
            deleteTail();
            return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != data) {
            temp = temp->next;
        }
        if (temp->next != NULL) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }
};

int main()
{
    LinkedList list;
    cout << "menu" << endl;
    cout << "1. addHead" << endl;
    cout << "2. addTail" << endl;
    cout << "3. contains" << endl;
    cout << "4. print" << endl;
    cout << "5. exit" << endl;
    cout << "6. deleteHead" << endl;
    cout << "7. deleteTail" << endl;
    cout << "8. deleteMiddle" << endl;
    int choice;
    do
    {
        cout << "choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "data: ";
            cin >> data;
            list.addHead(data);
            break;
        }
        case 2:
        {
            int data;
            cout << "data: ";
            cin >> data;
            list.addTail(data);
            break;
        }
        case 3:
        {
            int data;
            cout << "data: ";
            cin >> data;
            cout << list.contains(data) << endl;
            break;
        }
        case 4:
        {
            list.print();
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            list.deleteHead();
            break;
        }
        case 7:
        {
            list.deleteTail();
            break;
        }
        case 8:
        {
            int data;
            cout << "data: ";
            cin >> data;
            list.deleteMiddle(data);
            break;
        }
        default:
        {
            cout << "invalid choice" << endl;
            break;
        }
        }
    } while (choice != 8);
    return 0;
}