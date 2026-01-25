#include<iostream>
using namespace std;
class node{
public:
    int val;
    node*next;
    node*prev;
    node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }  
};
class linkedlist{
public:
    node*head;
    node*tail;
    int size;
    linkedlist(){
        head=tail=NULL;
        size=0;
    }
    node* add(node*head,int val){  //in circular linked list at end add 50
        node*temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        node*t=new node(val);
        temp->next=t;
        t->prev=temp;
        t->next=head;
        head->prev=t;
        temp=t;
        return head;
    }
    void display(node*head){
        if(head == NULL ) return;
        node* temp = head;
        do {
            cout << temp->val << " ";
            temp = temp->next;
        } while(temp != head);
            cout << endl;
    }
};
int main(){
    linkedlist ll;
    node* a=new node(10);  
    node* b=new node(20);
    node* c=new node(30);
    node* d=new node(40);
    node* e=new node(50);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=a;
    a->prev=e;//doubly
    e->prev=d;//
    d->prev=c;
    c->prev=b;
    b->prev=a;
    node*result =ll.add(a,60);
    ll.display(result);

}