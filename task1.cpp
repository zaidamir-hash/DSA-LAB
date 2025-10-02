#include <iostream>
using namespace std;

struct Node{
    Node* prev;
    Node* next;
    int data;

public:
    Node(int d){
        prev = nullptr;
        next = nullptr;
        data = d;

    }


};

class LinkedList{
    Node* head;
public:
    LinkedList(){
        head = nullptr;
    }


    Node* gethead(){
        return head;
    }

    void sethead(Node* newhead) {
        head = newhead;
    }



    void addnodetofront(int data){
        Node* newnode = new Node(data);
        if(head == nullptr){
            head = newnode;
            return;
        }

        newnode->next = head;
        head->prev = newnode;
        head = newnode;


    }

    void addtoend(int data){
        Node* newnode = new Node(data);
        if(head == nullptr){
            head = newnode;
            return;
        }
        Node* current = head;
        while(current->next!=nullptr){
            current = current->next;
        }
        current->next = newnode;
        newnode->prev = current;

    }

    void deletefromfront(){
        if(head == nullptr){
            cout<<" List is empty";
            return;
        }

        Node* temp = head;
        head = head->next;

        if(head!=nullptr){
            head->prev = nullptr;
        }
        delete temp;
    }

    void deletefromend(){
        if(head == nullptr){
            cout<<"List is empty";
            return;
        }

        Node* current = head;
        while(current->next!=nullptr){
            current = current->next;
        }
        Node* temp = current;
        current->prev->next = nullptr;
        delete temp;
    }


    void deletefromposition(int pos){

        if(head==nullptr){
            cout<<"List is empty";
            return;
        }
        if(pos==1){
            Node* temp = head;
            head= head->next;
            if(head!=nullptr){
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        Node* current = head;
        for(int i =1;i<pos;i++){
            current = current->next;
            if(current == nullptr){
                cout<<"Position out of range";
                return;
            }
           
        
        }
        if(current->prev!=nullptr){
            current->prev->next = current->next;

        }
        if(current->next!=nullptr){
           current->next->prev = current->prev;

        }
        
        delete current;

    }   



    

    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }

        cout<<"NULL\n";
    }

    Node* recursivereverse(Node* head){
        
        if(head==nullptr||head->next == nullptr){
            if(head!=nullptr){
                head->prev = nullptr;
            }
            return head;
        }

        Node* next = head->next;
        Node*newhead = recursivereverse(next);
    
        next->next = head;
        head->prev = next;
        head->next = nullptr;

        return newhead; 


    }
};





int main(){
    LinkedList l1;
    l1.addtoend(5);
    l1.addtoend(6);
    l1.addtoend(7);
    l1.sethead(l1.recursivereverse(l1.gethead()));  
    l1.display();
    l1.deletefromposition(3);
    l1.deletefromend();
    l1.deletefromfront();

}