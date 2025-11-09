#include <iostream>
using namespace std;

struct Node{ 
    int val; 
    Node* left; 
    Node* right; 
    Node(int v): val(v), left(NULL), right(NULL){} 
};

bool isBST(Node* root, Node*& prev){
    if(!root) return true;
    if(!isBST(root->left, prev)) return false;
    if(prev && root->val <= prev->val) return false;
    prev = root;
    return isBST(root->right, prev);
}

int main(){
    Node* bst = new Node(20);
    bst->left = new Node(10);
    bst->right = new Node(30);
    bst->left->left = new Node(5);
    bst->left->right = new Node(15);

    Node* prev = nullptr;
    cout<<"Tree is BST? "<<(isBST(bst, prev) ? "Yes":"No")<<"\n";

    Node* notbst = new Node(20);
    notbst->left = new Node(30);
    notbst->right = new Node(10);

    prev = nullptr;
    cout<<"Second tree is BST? "<<(isBST(notbst, prev) ? "Yes":"No")<<"\n";

    return 0;
}
