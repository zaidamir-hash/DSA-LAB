#include <iostream>
using namespace std;

struct Node {
    Node* next;
    int data;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = NULL;
    }



    void addtoend(int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = newnode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    Node* gethead(){
        return head;
    }

    bool recursivesearchLL(Node*current,int value){

        if(current == nullptr){
            return false;
        }
        
        bool found = recursivesearchLL(current->next,value);

        if(current->data == value){
            cout<< "Data found "<<value<<endl;
            return true;
        }

        return found;




    }


};


int main() {
    int numbers[] = {3, 1, 2, 5, 8};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    LinkedList myList;
    for (int i = 0; i < length; i++) {
        myList.addtoend(numbers[i]);
    }

    int key =2;

    if (!myList.recursivesearchLL(myList.gethead(), key)) {
        cout << "Data not found: " << key << endl;
    }


}