#include <iostream>
using namespace std;

struct Node{

	
	int data;
	Node* next;
	
	Node(int d){
		data = d;
		next = NULL;
		
		
	}
	
	

};

class LinkedList{
	Node* head;
	public:
		LinkedList(){
			head = NULL;
		}
		
		
		
		void add_node(int data){
		
			
			Node* n = new Node(data);
			if(head == NULL){
				head=n;
				return;
			}
			Node* current = head;
			while(current->next!=NULL){
				current = current->next;
			}
			
			current->next = n;
		
		
		}
		
		void bubblesortlinkedlist() {
        if (head == nullptr || head->next == nullptr) return;

        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current->next != nullptr) {
                if (current->data > current->next->data) {
                    swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }
		
		
	
		void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    } 
			
	
	
	

	
};


int main(){
	LinkedList l1;
	l1.add_node(6);
	l1.add_node(5);
	l1.add_node(4);
	l1.display();
	l1.bubblesortlinkedlist();
	l1.display();
	
}
	
	