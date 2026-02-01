#include<iostream>
using namespace std;
class node{
public:
    int val;
    node*next;
    node*prev;   //one more add that store previous address
    node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
    
};
//normal dispaly kartu
void display(node*head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}
//reverse function
void displayreverse(node*tail){
    while(tail!=NULL){
        cout<<tail->val<<" ";
        tail=tail->prev;
    }
}
//display using recursion
void displayrec(node*head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    display(head->next);
    cout<<head->val<<" ";
}
int main(){
    //10 20 30 40 50
    node*a=new node(10);
    node*b=new node(20);
    node*c=new node(30);
    node*d=new node(40);
    node*e=new node(50);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    //doubly
    e->prev=d;
    d->prev=c;
    c->prev=b;
    b->prev=a;
    display(a);  //
    cout<<endl;
    displayreverse(e); //reverse linked list printing
}