#include <iostream>
#include <string>
using namespace std;
struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int k):key(k),left(NULL),right(NULL){}
};
Node* insertNode(Node* root,int k){
    if(!root) return new Node(k);
    if(k < root->key) root->left = insertNode(root->left,k);
    else if(k > root->key) root->right = insertNode(root->right,k);
    return root;
}
Node* findMin(Node* root){
    while(root && root->left) root = root->left;
    return root;
}
Node* deleteNode(Node* root,int k){
    if(!root) return NULL;
    if(k < root->key) root->left = deleteNode(root->left,k);
    else if(k > root->key) root->right = deleteNode(root->right,k);
    else{
        if(!root->left){
            Node* r = root->right;
            delete root;
            return r;
        } else if(!root->right){
            Node* l = root->left;
            delete root;
            return l;
        } else{
            Node* mn = findMin(root->right);
            root->key = mn->key;
            root->right = deleteNode(root->right,mn->key);
        }
    }
    return root;
}
bool searchNode(Node* root,int k){
    if(!root) return false;
    if(root->key==k) return true;
    if(k < root->key) return searchNode(root->left,k);
    return searchNode(root->right,k);
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
void preorder(Node* root){
    if(!root) return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
}
int main(){
    Node* root = NULL;
    int arr[] = {50,30,70,20,40,60,80};
    for(int i=0;i<7;i++) root = insertNode(root,arr[i]);
    cout<<"Inorder: "; inorder(root); cout<<"\n";
    cout<<"Preorder: "; preorder(root); cout<<"\n";
    cout<<"Postorder: "; postorder(root); cout<<"\n";
    cout<<"Search 40: "<<(searchNode(root,40) ? "Found":"Not Found")<<"\n";
    root = deleteNode(root,50);
    cout<<"After deleting 50, Inorder: "; inorder(root); cout<<"\n";
    return 0;
}
