//138
#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node*next;
    Node*random;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class linkedlist{
public:
    Node*head;
    Node*tail;
    int size;
    linkedlist(){
        head=tail=NULL;
        size=0;
    }
    Node* copyRandomList(Node* head) {
        //step 1 ->create a deep copy
        Node*temp=head;
        Node*dummy=new Node(100);
        Node*tempC=dummy;  
        while(temp!=NULL){
            Node*a=new Node(temp->val);
            tempC->next=a;
            temp=temp->next;
            tempC=tempC->next;
        }
        Node* duplicate=dummy->next;
        //step 2 -> alternate connection
        Node* a=head;
        Node* b=duplicate;
        dummy =new Node(-1);
        Node*tempD=dummy;
        while(b!=NULL){
            tempD->next=a;
            a=a->next;
            tempD=tempD->next;
            tempD->next=b;
            b=b->next;
            tempD=tempD->next;
        }
        dummy=dummy->next;
        //step 3 -> assinging random pointer 
        Node* t1=dummy;   //t1 will traverse in the original list
        while(t1!=NULL){
            Node*t2=t1->next;
            if(t1->random!=NULL) t2->random=t1->random->next;
            t1=t1->next->next;
        }
        //step 4 ->removing a connection
        Node*d1=new Node(100);
        t1=d1;
        Node*d2=new Node(100);
        Node*t2=d2;
        Node* t=dummy;
        while(t!=NULL){
            t1->next=t;
            t=t->next;
            t1=t1->next;
            t2->next=t;
            t2=t2->next;
            t=t->next;
        }
        t1->next=NULL;
        t2->next=NULL;
        d1=d1->next;   //origial with random
        d2=d2->next;   //duplicate with random
        return d2;
    }
};
int main(){
    linkedlist ll;
    Node* a = new Node(10);  
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    // Next pointers
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    // Random pointers
    a->random = c;  // 10 -> 30
    b->random = a;  // 20 -> 10
    c->random = e;  // 30 -> 50
    d->random = b; // 40 -> 20
    e->random = NULL;  // 50 -> NULL

    cout << "Original List (val, random->val):" << endl;
    Node* temp = a;
    while (temp != NULL) {
        cout << temp->val << " , random-> ";
        if (temp->random) cout << temp->random->val;
        else cout << "NULL";
        cout << endl;
        temp = temp->next;
    }

    // Copy the list
    Node* copied = ll.copyRandomList(a);

    cout << "\nCopied List (val, random->val):" << endl;
    temp = copied;
    while (temp != NULL) {
        cout << temp->val << " , random-> ";
        if (temp->random) cout << temp->random->val;
        else cout << "NULL";
        cout << endl;
        temp = temp->next;
    }
}