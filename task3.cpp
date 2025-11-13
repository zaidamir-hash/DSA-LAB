#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    int height;
    Node(int v) : val(v), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* n) {
    return n ? n->height : 0;
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* node, int val) {
    if(!node) return new Node(val);
    if(val < node->val) node->left = insert(node->left, val);
    else if(val > node->val) node->right = insert(node->right, val);

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if(balance > 1 && val < node->left->val) return rightRotate(node);
    if(balance < -1 && val > node->right->val) return leftRotate(node);
    if(balance > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(Node* root) {
    if(root) {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void printBalanceFactors(Node* root) {
    if(root) {
        cout << "Node " << root->val << " → Balance Factor: " << getBalance(root) << endl;
        printBalanceFactors(root->left);
        printBalanceFactors(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);

    cout << "PreOrder of AVL Tree: ";
    preOrder(root);
    cout << "\nHeight of AVL Tree: " << root->height << endl;

    cout << "\nBalance Factors of each node:\n";
    printBalanceFactors(root);

    return 0;
}
