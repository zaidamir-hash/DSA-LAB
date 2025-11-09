#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    int roll;
    int score;
    Student(string n, int r, int s): name(n), roll(r), score(s) {}
};

struct Node{
    Student data;
    Node* left;
    Node* right;
    Node(Student s): data(s), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, Student s){
    if(!root) return new Node(s);
    if(s.name < root->data.name) root->left = insert(root->left, s);
    else if(s.name > root->data.name) root->right = insert(root->right, s);
    return root;
}

Node* search(Node* root, const string& name){
    if(!root) return nullptr;
    if(root->data.name == name) return root;
    if(name < root->data.name) return search(root->left, name);
    return search(root->right, name);
}

Node* findMin(Node* root){
    while(root && root->left) root = root->left;
    return root;
}

Node* remove(Node* root, const string& name){
    if(!root) return nullptr;
    if(name < root->data.name) root->left = remove(root->left, name);
    else if(name > root->data.name) root->right = remove(root->right, name);
    else{
        if(!root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = remove(root->right, temp->data.name);
    }
    return root;
}

Node* deleteLowScore(Node* root){
    if(!root) return nullptr;
    root->left = deleteLowScore(root->left);
    root->right = deleteLowScore(root->right);
    if(root->data.score < 10) return remove(root, root->data.name);
    return root;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data.name << " " << root->data.roll << " " << root->data.score << "\n";
    inorder(root->right);
}

Student* findMaxScore(Node* root, Student*& maxStudent){
    if(!root) return maxStudent;
    if(!maxStudent || root->data.score > maxStudent->score) maxStudent = &root->data;
    findMaxScore(root->left, maxStudent);
    findMaxScore(root->right, maxStudent);
    return maxStudent;
}

int main(){
    Student arr[10] = {
        {"Alice", 1, 15}, {"Bob", 2, 8}, {"Charlie", 3, 20},
        {"David", 4, 5}, {"Eve", 5, 12}, {"Frank", 6, 18},
        {"Grace", 7, 9}, {"Hannah", 8, 25}, {"Ivy", 9, 7}, {"Jack", 10, 14}
    };

    Node* root = nullptr;
    root = insert(root, arr[0]);
    root = insert(root, arr[2]);
    root = insert(root, arr[4]);
    root = insert(root, arr[5]);
    root = insert(root, arr[7]);
    root = insert(root, arr[9]);
    root = insert(root, arr[1]);

    cout << "BST Inorder:\n";
    inorder(root);

    string searchName;
    cout << "\nEnter student name to search: ";
    cin >> searchName;
    Node* found = search(root, searchName);
    if(found) cout << "Found: " << found->data.name << " " << found->data.roll << " " << found->data.score << "\n";
    else cout << "Student not found\n";

    root = deleteLowScore(root);
    cout << "\nBST after deleting students with score < 10:\n";
    inorder(root);

    Student* maxStudent = nullptr;
    findMaxScore(root, maxStudent);
    if(maxStudent) cout << "\nStudent with max score: " << maxStudent->name << " " << maxStudent->roll << " " << maxStudent->score << "\n";

    return 0;
}
