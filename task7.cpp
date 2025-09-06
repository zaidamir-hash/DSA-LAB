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

class LinkedList{
    Node* head;
    Node* tail;

public:
    LinkedList(){
        head = NULL;
        tail =NULL;
    }

    void addtoend(int val){

        Node* newnode = new Node(val);

        Node* temp = head;

        if (head == NULL){
            head = newnode;
            tail = newnode;
            tail->next = head;
        }
        
        tail->next = newnode;
        tail = tail->next;
        tail->next = head;

    }

    void addtofront(int val){

        Node* newnode = new Node(val);
        
        if (head == NULL) { 
        head = newnode;
        tail = newnode;
        tail->next = head;
        }else{
            newnode->next = head;
            head = newnode;
            tail->next = head;

        }

       
    }

    void addatposition(int pos,int data){

        Node* newnode = new Node(data);


        if(head==NULL){
            if(pos == 1){
                head = newnode;
                tail = newnode;
                tail->next = head;

            }else{
                delete newnode;
            }

            return;
        }

        if(pos==1){
            newnode->next = head;
            head = newnode;
            tail->next = head;
            return;

        }

        Node* current_ptr = head;

        for(int i=1;i<pos-1;i++){

            current_ptr = current_ptr->next;

        }

        if (current_ptr == head) {
            delete newnode;
            return;
        }

        Node* temp = current_ptr->next;
        current_ptr->next = newnode;
        newnode->next = temp;


        if(current_ptr == tail){
            tail = newnode;
        }


    }

    
    
    void deletefromposition(int pos) {
        if (head == NULL) return; 

        Node* current_ptr = head;

        if (pos == 1) {
            if (head == tail) {  
                delete head;
                head = NULL;
                tail = NULL;
                return;
            }
            Node* temp = head;
            head = head->next;
            tail->next = head; 
            delete temp;
            return;
        }

        for (int i = 1; i < pos - 1 && current_ptr->next != head; i++) {
            current_ptr = current_ptr->next;
        }

        Node* temp = current_ptr->next;
        if (temp == head) return;

        current_ptr->next = temp->next;
        if (temp == tail) {
            tail = current_ptr;
        }

        delete temp;
    }


    void displaylist(){

        cout<<head->data<<" ";
        Node* current = head->next;


        while(current!=head){

            cout<<current->data<<" ";
            current = current->next;

        }
        cout<<endl;
    }

};

int main(){
    int numbers[] = {3,1,2,5};
    int length = sizeof(numbers)/sizeof(numbers[0]);

    cout<<" Initial array contents :"<<endl;

    for(int i=0;i<length;i++){
        cout<<numbers[i]<<" ";
    }

    cout << "\n\n";

    LinkedList myList;
    for (int i = 0; i < length; i++) {
        myList.addtoend(numbers[i]);
    }

    myList.addtoend(9);
    myList.addatposition(11, 3);
    myList.addtofront(4);
    myList.deletefromposition(3);
    cout << "Linked list after performing insertions:" << endl;
    myList.displaylist();

    myList.deletefromposition(1);
    myList.deletefromposition(2);
    myList.deletefromposition(5);

    cout << "Linked list after deleting specific values:" << endl;
    myList.displaylist();
    
}