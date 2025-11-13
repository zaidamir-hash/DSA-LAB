#include <iostream>
using namespace std;

struct Node {
    int roll;
    Node* left;
    Node* right;
    int height;
    Node(int r) : roll(r), left(nullptr), right(nullptr), height(1) {}
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

Node* insert(Node* node, int roll) {
    if (!node) return new Node(roll);

    if (roll < node->roll) node->left = insert(node->left, roll);
    else if (roll > node->roll) node->right = insert(node->right, roll);

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

   
    if (balance > 1 && roll < node->left->roll)
        return rightRotate(node);

 
    if (balance < -1 && roll > node->right->roll)
        return leftRotate(node);


    if (balance > 1 && roll > node->left->roll) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

 
    if (balance < -1 && roll < node->right->roll) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node* root) {
    if (root) {
        cout << root->roll << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;

   
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

  
    root = insert(root, 15);

   
    cout << "PreOrder of AVL Tree: ";
    preOrder(root);
    cout << "\nHeight of AVL Tree: " << root->height << endl;

    return 0;
}
