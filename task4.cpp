#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) { data = d; next = NULL; }
};

class Stack {
    Node* top;
public:
    Stack() { top = NULL; }
    void push(string val) {
        Node* n = new Node(val);
        n->next = top;
        top = n;
    }
    string pop() {
        if (!top) return "";
        string val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    string peek() { return top ? top->data : ""; }
    bool isEmpty() { return top == NULL; }
    void display() {
        Node* curr = top;
        while (curr) {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
};

int main() {
    Stack s;
    s.push("x");
    s.push("=");
    double result = 12 + 13 - 5 * (0.5 + 0.5) + 1;
    stringstream ss;
    ss << result;
    s.push(ss.str());
    s.display();
}
