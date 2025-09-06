#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void concatenate(DoublyLinkedList &M) {
        if (!M.head) return;
        if (!head) {
            head = M.head;
            tail = M.tail;
            return;
        }
        tail->next = M.head;
        M.head->prev = tail;
        tail = M.tail;
    }

    void printForward() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printBackward() {
        Node* temp = tail;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList L;
    L.append(1);
    L.append(2);
    L.append(3);

    DoublyLinkedList M;
    M.append(4);
    M.append(5);
    M.append(6);

    cout << "List L: ";
    L.printForward();
    cout << "List M: ";
    M.printForward();

    L.concatenate(M);

    cout << "Concatenated List Forward: ";
    L.printForward();
    cout << "Concatenated List Backward: ";
    L.printBackward();

    return 0;
}
