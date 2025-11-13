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

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
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

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 55);
    root = leftRotate(root);
    cout << "PreOrder after left rotation on root: ";
    preOrder(root);
    cout << endl;
}
