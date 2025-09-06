#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
    }

    void extractReverseAppend() {
        if (!head || !head->next) return;

        Node* prev = head;
        Node* curr = head->next;
        Node* altHead = nullptr;
        Node* altTail = nullptr;

        while (curr) {
            prev->next = curr->next;
            curr->next = altHead;
            altHead = curr;
            if (!altTail) altTail = curr;
            prev = prev->next;
            if (prev) curr = prev->next;
            else break;
        }

        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = altHead;
    }

    void printList() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.append(10);
    list.append(4);
    list.append(9);
    list.append(1);
    list.append(3);
    list.append(5);
    list.append(9);
    list.append(4);

    list.extractReverseAppend();
    list.printList();

    return 0;
}
