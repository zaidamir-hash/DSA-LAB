#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    string arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(string item) {
        if (top == MAX - 1) return;
        arr[++top] = item;
    }
    bool isEmpty() {
        return top == -1;
    }
    void pop() {
        if (!isEmpty()) top--;
    }
    string peek() {
        if (!isEmpty()) return arr[top];
        return "";
    }
};

int main() {
    Stack s;
    s.push("Finish report");
    s.push("Call client");
    if (!s.isEmpty()) {
        cout << "Top: " << s.peek() << endl;
        s.pop();
    }
}
