#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    bool isPalindrome() {
       
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        if (count == 0 || count == 1) return true;

        
        int* arr = new int[count];
        temp = head;
        for (int i = 0; i < count; i++) {
            arr[i] = temp->data;
            temp = temp->next;
        }

        int i = 0, j = count - 1;
        while (i < j) {
            if (arr[i] != arr[j]) {
                delete[] arr;
                return false;
            }
            i++;
            j--;
        }

        delete[] arr;
        return true;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(2);
    list.append(1);

    cout << "List: ";
    list.display();

    if (list.isPalindrome())
        cout << "The list is a palindrome." << endl;
    else
        cout << "The list is not a palindrome." << endl;

    return 0;
}
