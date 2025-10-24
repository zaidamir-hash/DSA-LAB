#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    void push(char c) { if (top < MAX - 1) arr[++top] = c; }
    void pop() { if (top >= 0) top--; }
    char peek() { return (top >= 0) ? arr[top] : '\0'; }
    bool isEmpty() { return top == -1; }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

string infixToPostfix(string exp) {
    Stack s;
    string result = "";
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (isalnum(c)) result += c;
        else if (c == '(') s.push(c);
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                result += s.peek();
                s.pop();
            }
            if (!s.isEmpty()) s.pop();
        } 
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c) && c != '^') {
                result += s.peek();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        result += s.peek();
        s.pop();
    }
    return result;
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << infixToPostfix(exp);
}
