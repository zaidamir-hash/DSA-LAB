#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(NULL), right(NULL){}
};

Node* insert(Node* root, int key){
    if(!root) return new Node(key);
    if(key < root->val) root->left = insert(root->left, key);
    else if(key > root->val) root->right = insert(root->right, key);
    return root;
}

bool search(Node* root, int key){
    if(!root) return false;
    if(root->val == key) return true;
    if(key < root->val) return search(root->left, key);
    return search(root->right, key);
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
    Node* bst = new Node(20);
    bst->left = new Node(10);
    bst->right = new Node(30);
    bst->left->left = new Node(5);
    bst->left->right = new Node(15);

    cout << "Enter value to search/insert: ";
    int key;
    cin >> key;

    if(!search(bst, key)) bst = insert(bst, key);

    cout << "BST in-order: ";
    inorder(bst);
    cout << "\n";
    return 0;
}
