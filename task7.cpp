#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class LibraryQueue {
    string patrons[MAX];
    int front, rear;
public:
    LibraryQueue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == MAX - 1; }

    void addPatron(string name) {
        if (isFull()) {
            cout << "Queue is full. Cannot add more patrons.\n";
            return;
        }
        if (front == -1) front = 0;
        patrons[++rear] = name;
        cout << name << " has joined the queue.\n";
    }

    void completeTransaction() {
        if (isEmpty()) {
            cout << "No patrons in queue.\n";
            return;
        }
        cout << patrons[front] << " has completed their transaction.\n";
        front++;
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "No patrons are currently waiting.\n";
            return;
        }
        cout << "Current patrons in queue: ";
        for (int i = front; i <= rear; i++) cout << patrons[i] << " ";
        cout << endl;
    }
};

int main() {
    LibraryQueue lq;
    lq.addPatron("Ali Raza");
    lq.addPatron("Hassan Khan");
    lq.addPatron("Sherrin");
    lq.addPatron("Muazzam");

    lq.displayQueue();

    lq.completeTransaction();
    lq.completeTransaction();

    lq.displayQueue();

    lq.addPatron("Mohsin");
    lq.displayQueue();
}
