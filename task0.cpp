//AVL trees are self-balancing binary search trees that maintain the height difference (balance factor) of any node between -1 and 1, ensuring operations like insertion, deletion, and search remain O(log n).

//They are used to guarantee fast search and update times even in the worst case.


#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int k): key(k), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* n){
    return n ? n->height : 0;
}

int getBalance(Node* n){
    return n ? height(n->left) - height(n->right) : 0;
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node* convertToAVL(Node* root){
    if(!root) return root;
    root->left = convertToAVL(root->left);
    root->right = convertToAVL(root->right);
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if(balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
    if(balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
    if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

int main(){
    Node* A = new Node(10);
    A->left = new Node(6);
    A->left->left = new Node(4);
    A->left->right = new Node(8);

    Node* B = new Node(10);
    B->right = new Node(16);
    B->right->left = new Node(12);
    B->right->right = new Node(18);

    A = convertToAVL(A);
    B = convertToAVL(B);

    cout << "Conversion complete.\n";
    return 0;
}


/ Step-by-step conversion of A

// Leaves 4 and 8 → balanced (0).

// Node 6: height(left)=1, height(right)=1 → balance=0 → no rotation.

// Root 10: height(left)=2, height(right)=0 → balance=+2 → Left Heavy → Single Right Rotation.

// Right Rotation: y=10, x=y->left=6, t2=x->right=8;
// x->right=y, y->left=t2 → 6 becomes new root, 10 becomes right child.

// Step-by-step conversion of B

// Leaves 12 and 18 → balanced (0).

// Node 16: balance=0 → balanced.

// Root 10: height(left)=0, height(right)=2 → balance=-2 → Right Heavy → Single Left Rotation.

// Left Rotation: x=10, y=x->right=16, t2=y->left=12;
// y->left=x, x->right=t2 → 16 becomes new root, 10 becomes left child.

// Summary:

// convertToAVL() checks balance factors and applies rotations (Right/Left) as needed.

// Temporary pointers x, y, t2 hold subtrees during rotation.

// New subtree root is returned to maintain correct parent links and AVL balance.


