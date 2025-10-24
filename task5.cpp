#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == MAX - 1; }

    void enqueue(int id) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = id;
    }

    void dequeue() {
        if (isEmpty()) return;
        front++;
    }

    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    void display() {
        if (isEmpty()) return;
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int customers[] = {13, 7, 4, 1, 6, 8, 10};
    for (int i = 0; i < 7; i++) q.enqueue(customers[i]);

    q.display();

    cout << "Serving Customer ID: " << q.peek() << endl;
    q.dequeue();

    q.display();
}
