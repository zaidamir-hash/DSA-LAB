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
		

        Node* getHead() {   
            return head;
        }

        void alternatepositions(Node* head1,Node* head2){
            Node* temp1 = head1;
            Node* temp2 = head2;    
            
            while(temp1!=nullptr && temp2!=nullptr){
                
                Node* temp = temp1->next;
                Node* temp0= temp2->next;
                temp1->next = temp2;
                temp2->next = temp ;
                
                temp1  = temp;
                temp2 = temp0;
            }
            


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
	l1.add_node(1);
	l1.add_node(2);
	l1.add_node(3);
	l1.display();
    LinkedList l2;
    l2.add_node(4);
	l2.add_node(5);
	l2.add_node(6);
    l2.add_node(7);
	l2.add_node(8);
    l2.display();
    l2.alternatepositions(l1.getHead(),l2.getHead());
    l1.display();

   


	
	
}
	