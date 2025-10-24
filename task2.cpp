#include <iostream>
using namespace std;

struct Node {
    string url;
    Node* next;
    Node(string u) { url = u; next = NULL; }
};

class Stack {
    string arr[100];
    int top;
public:
    Stack() { top = -1; }
    void push(string url) { if (top < 99) arr[++top] = url; }
    void pop() { if (top >= 0) top--; }
    string peek() { return (top >= 0) ? arr[top] : ""; }
    bool isEmpty() { return top == -1; }
};

class BrowserHistory {
    Node* head;
    Stack s;
public:
    BrowserHistory() { head = NULL; }
    void visit(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
        s.push(url);
    }
    void goBack(int times) {
        for (int i = 0; i < times; i++) {
            if (head) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            if (!s.isEmpty()) s.pop();
        }
    }
    void currentPage() {
        cout << "Current Page: " << (head ? head->url : "None") << endl;
    }
};

int main() {
    BrowserHistory bh;
    bh.visit("Google");
    bh.visit("Facebook");
    bh.visit("Twitter");
    bh.visit("LinkedIn");
    bh.visit("Instagram");
    bh.goBack(2);
    bh.currentPage();
}
