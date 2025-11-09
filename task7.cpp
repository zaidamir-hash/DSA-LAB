#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int d):data(d),left(NULL),right(NULL){}
};

Node* insertNode(Node* root,int val){
    if(!root) return new Node(val);
    if(val < root->data) root->left = insertNode(root->left,val);
    else if(val > root->data) root->right = insertNode(root->right,val);
    return root;
}

int countNodes(Node* root){
    if(!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorderStore(Node* root,int arr[],int &i){
    if(!root) return;
    inorderStore(root->left,arr,i);
    arr[i++] = root->data;
    inorderStore(root->right,arr,i);
}

double findMedian(Node* root){
    int n = countNodes(root);
    if(n == 0) return 0;
    int* arr = new int[n];
    int i = 0;
    inorderStore(root,arr,i);
    double median;
    if(n % 2 == 1) median = arr[(n+1)/2 - 1];
    else median = (arr[n/2 - 1] + arr[n/2]) / 2.0;
    delete [] arr;
    return median;
}

int main(){
    Node* root = NULL;
    int arr[] = {20,8,22,4,12,10,14};
    for(int i=0;i<7;i++) root = insertNode(root,arr[i]);
    cout<<"Median of BST: "<<findMedian(root)<<"\n";
    return 0;
}
