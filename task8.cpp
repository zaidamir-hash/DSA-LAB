#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int v):val(v),left(NULL),right(NULL){}
};

Node* insertNode(Node* r,int v){
    if(!r) return new Node(v);
    if(v<r->val) r->left = insertNode(r->left,v);
    else if(v>r->val) r->right = insertNode(r->right,v);
    return r;
}

void nodesInRange(Node* root,int a,int b,int &count){
    if(!root) return;
    if(root->val > a) nodesInRange(root->left,a,b,count);
    if(root->val >= a && root->val <= b){
        cout<<root->val<<" ";
        count++;
    }
    if(root->val < b) nodesInRange(root->right,a,b,count);
}

int main(){
    Node* root = NULL;
    root = insertNode(root,10);
    root = insertNode(root,5);
    root = insertNode(root,50);
    root = insertNode(root,1);
    root = insertNode(root,40);
    root = insertNode(root,100);

    int a = 5, b = 45;
    int count = 0;
    cout<<"Output: ";
    nodesInRange(root,a,b,count);
    cout<<"\nExplanation: There are "<<count<<" nodes in range ["<<a<<", "<<b<<"] = ";
    int c = 0;
    nodesInRange(root,a,b,c);
    cout<<"\n";
    return 0;
}
