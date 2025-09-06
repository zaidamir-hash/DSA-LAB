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

    void addtofront(int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = newnode;
        } else {
            newnode->next = head;
            head = newnode;
        }
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


    void deletefromposition(int pos){

        Node* current_ptr = head;
        Node* prev_ptr = NULL;


        if(pos == 1){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
       
        for(int i=1;i<pos-1 && current_ptr!=NULL;i++){
           
            current_ptr= current_ptr->next;

        }

        Node* temp = current_ptr->next;
        current_ptr->next = temp->next;
        delete temp;

        

    
        
    

        
    }


    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

};

int main() {
    int numbers[] = {3, 1, 2, 5, 8};
    int length = sizeof(numbers) / sizeof(numbers[0]);

    cout << "Initial array contents:" << endl;
    for (int i = 0; i < length; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n\n";

    LinkedList myList;
    for (int i = 0; i < length; i++) {
        myList.addtoend(numbers[i]);
    }

    myList.deletefromposition(3);
    cout<<" Linked List after deleting from position 3"<<endl;
    myList.printList();
}
