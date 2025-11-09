#include <iostream>
using namespace std;

struct Product{
    int id;
    int quantity;
    Product(int i, int q): id(i), quantity(q) {}
};

struct Node{
    Product data;
    Node* left;
    Node* right;
    Node(Product p): data(p), left(nullptr), right(nullptr) {}
};

class InventoryBST{
    Node* root;

    Node* insert(Node* node, Product p){
        if(!node) return new Node(p);
        if(p.id < node->data.id) node->left = insert(node->left, p);
        else if(p.id > node->data.id) node->right = insert(node->right, p);
        return node;
    }

    Node* search(Node* node, int id){
        if(!node) return nullptr;
        if(node->data.id == id) return node;
        if(id < node->data.id) return search(node->left, id);
        return search(node->right, id);
    }

    void findMaxQuantity(Node* node, Node*& maxNode){
        if(!node) return;
        if(!maxNode || node->data.quantity > maxNode->data.quantity) maxNode = node;
        findMaxQuantity(node->left, maxNode);
        findMaxQuantity(node->right, maxNode);
    }

public:
    InventoryBST(): root(nullptr) {}

    void insertProduct(int id, int quantity){
        Node* existing = search(root, id);
        if(existing) existing->data.quantity = quantity; // update
        else root = insert(root, Product(id, quantity)); // new product
    }

    void updateQuantity(int id, int quantity){
        Node* existing = search(root, id);
        if(existing) existing->data.quantity = quantity;
        else cout << "Product ID " << id << " not found.\n";
    }

    void searchProduct(int id){
        Node* p = search(root, id);
        if(p) cout << "Product ID: " << p->data.id << ", Quantity: " << p->data.quantity << "\n";
        else cout << "Product ID " << id << " not found.\n";
    }

    void maxQuantityProduct(){
        Node* maxNode = nullptr;
        findMaxQuantity(root, maxNode);
        if(maxNode) cout << "Max Quantity Product ID: " << maxNode->data.id 
                          << ", Quantity: " << maxNode->data.quantity << "\n";
        else cout << "Inventory is empty.\n";
    }
};

int main(){
    InventoryBST inventory;
    inventory.insertProduct(101, 50);
    inventory.insertProduct(102, 20);
    inventory.insertProduct(103, 75);
    inventory.insertProduct(104, 40);

    inventory.searchProduct(102);
    inventory.updateQuantity(102, 60);
    inventory.searchProduct(102);

    inventory.maxQuantityProduct();

    return 0;
}
