#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Combatant{
    string name;
    int hp;
    int atk;
    Combatant(string n="",int h=0,int a=0):name(n),hp(h),atk(a){}
};
struct Node{
    Combatant c;
    Node* left;
    Node* right;
    Node(const Combatant& cc):c(cc),left(NULL),right(NULL){}
};
Node* insertNode(Node* root,const Combatant& c){
    if(!root) return new Node(c);
    if(c.name < root->c.name) root->left = insertNode(root->left,c);
    else if(c.name > root->c.name) root->right = insertNode(root->right,c);
    return root;
}
Node* findMin(Node* root){
    if(!root) return NULL;
    while(root->left) root=root->left;
    return root;
}
Node* deleteByName(Node* root,const string& name){
    if(!root) return NULL;
    if(name < root->c.name) root->left = deleteByName(root->left,name);
    else if(name > root->c.name) root->right = deleteByName(root->right,name);
    else{
        if(!root->left){
            Node* r = root->right; delete root; return r;
        } else if(!root->right){
            Node* l = root->left; delete root; return l;
        } else{
            Node* mn = findMin(root->right);
            root->c = mn->c;
            root->right = deleteByName(root->right,mn->c.name);
        }
    }
    return root;
}
void printInOrder(Node* root){
    if(!root) return;
    printInOrder(root->left);
    cout<<root->c.name<<"(HP:"<<root->c.hp<<") ";
    printInOrder(root->right);
}
bool emptyTree(Node* root){ return root==NULL; }
void freeTree(Node* root){ if(!root) return; freeTree(root->left); freeTree(root->right); delete root; }
int main(){
    srand((unsigned)time(0));
    Node* heroes = NULL;
    Node* enemies = NULL;
    Combatant hlist[5] = {{"Arin",30,6},{"Borin",28,7},{"Cora",26,5},{"Dax",32,4},{"Elya",24,8}};
    Combatant elist[5] = {{"Gob1",20,5},{"Gob2",22,6},{"OrcA",34,7},{"OrcB",30,6},{"Troll",40,8}};
    for(int i=0;i<5;i++) heroes = insertNode(heroes,hlist[i]);
    for(int i=0;i<5;i++) enemies = insertNode(enemies,elist[i]);
    int round = 1;
    while(!emptyTree(heroes) && !emptyTree(enemies)){
        cout<<"====================\n";
        cout<<"Round "<<round<<"\n";
        cout<<"Heroes: "; printInOrder(heroes); cout<<"\n";
        cout<<"Enemies: "; printInOrder(enemies); cout<<"\n";
        Node* pFront = findMin(heroes);
        Node* eFront = findMin(enemies);
        if(!pFront || !eFront) break;
        cout<<"Player attacker: "<<pFront->c.name<<" (HP:"<<pFront->c.hp<<") vs Enemy defender: "<<eFront->c.name<<" (HP:"<<eFront->c.hp<<")\n";
        int dmg = pFront->c.atk + (rand()%5);
        cout<<pFront->c.name<<" deals "<<dmg<<" damage to "<<eFront->c.name<<"\n";
        eFront->c.hp -= dmg;
        if(eFront->c.hp <= 0){
            cout<<eFront->c.name<<" is defeated!\n";
            enemies = deleteByName(enemies,eFront->c.name);
            if(emptyTree(enemies)) break;
            eFront = findMin(enemies);
        } else {
            cout<<eFront->c.name<<" now has HP "<<eFront->c.hp<<"\n";
        }
        cout<<"Enemy counterattack: "<<(eFront?eFront->c.name:"(none)")<<"\n";
        if(eFront){
            dmg = eFront->c.atk + (rand()%5);
            cout<<eFront->c.name<<" deals "<<dmg<<" damage to "<<pFront->c.name<<"\n";
            pFront->c.hp -= dmg;
            if(pFront->c.hp <= 0){
                cout<<pFront->c.name<<" is defeated!\n";
                heroes = deleteByName(heroes,pFront->c.name);
            } else {
                cout<<pFront->c.name<<" now has HP "<<pFront->c.hp<<"\n";
            }
        }
        round++;
    }
    if(emptyTree(enemies)) cout<<"Victory! All enemies defeated.\n";
    else if(emptyTree(heroes)) cout<<"Defeat! All heroes have fallen.\n";
    freeTree(heroes);
    freeTree(enemies);
    return 0;
}
