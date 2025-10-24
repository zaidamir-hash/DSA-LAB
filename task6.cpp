#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class MessageQueue {
    string arr[MAX];
    int front, rear;
public:
    MessageQueue() { front = -1; rear = -1; }

    bool isEmpty() { return front == -1 || front > rear; }
    bool isFull() { return rear == MAX - 1; }

    void enqueue(string msg) {
        if (isFull()) return;
        if (front == -1) front = 0;
        arr[++rear] = msg;
    }

    void dequeue() {
        if (isEmpty()) return;
        cout << "Processing message: " << arr[front] << endl;
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "No messages in queue\n";
            return;
        }
        cout << "Messages waiting: ";
        for (int i = front; i <= rear; i++) cout << arr[i] << " | ";
        cout << endl;
    }
};

int main() {
    MessageQueue mq;
    mq.enqueue("Hello");
    mq.enqueue("How are you?");
    mq.enqueue("Meeting at 12am");
    mq.enqueue("Send report");

    mq.display();

    mq.dequeue();
    mq.dequeue();

    mq.display();
}
