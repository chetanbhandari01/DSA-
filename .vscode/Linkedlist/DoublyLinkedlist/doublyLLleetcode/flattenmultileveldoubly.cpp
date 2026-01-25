#include<iostream>
using namespace std;
class node{
public:
    int val;
    node*next;
    node*prev;   //one more add that store previous address
    node*child;
    node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
        this->child=NULL;
    }
    
};
class ddl{
public:
    node*flatten(node*head){
        node*temp=head;
        while(temp!=NULL){
            node*a=temp->next;
            if(temp->child!=NULL){
                node*c=temp->child;
                temp->child=NULL;
                c=flatten(c);
                temp->next=c;
                c->prev=temp;
                while(c!=NULL){
                    c=c->next;
                }
                c->next=a;
                if(a!=NULL) a->prev=c;
            }
            temp=a;
        }
        return head;
    }
};
int main() {
    ddl d;

    // Create nodes
    node* a = new node(1);
    node* b = new node(2);
    node* c = new node(3);
    node* d1 = new node(4);
    node* e = new node(5);
    node* f = new node(6);

    // Link main list: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6
    a->next = b; b->prev = a;
    b->next = c; c->prev = b;
    c->next = d1; d1->prev = c;
    d1->next = e; e->prev = d1;
    e->next = f; f->prev = e;

    // Add child: node 3 has child 7->8->9
    node* x = new node(7);
    node* y = new node(8);
    node* z = new node(9);
    x->next = y; y->prev = x;
    y->next = z; z->prev = y;
    c->child = x;

    cout << "Original List (before flatten):" << endl;
    node* temp = a;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    // Flatten the list
    node* result = d.flatten(a);

    cout << "Flattened List:" << endl;
    temp = result;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
