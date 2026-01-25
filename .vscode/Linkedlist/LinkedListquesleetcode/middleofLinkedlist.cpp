#include<iostream>
using namespace std;
class node{
public:
    int val;
    node*next;
    node(int val){
        this->val=val;
        this->next=NULL;
    }
};
node* listnode(node* head){
    node*slow=head;
    node*fast=head;
    while(fast !=NULL && fast->next !=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
void display(node*slow){
    cout<<slow->val;
}
int main(){
    node* a=new node(10);  
    node* b=new node(20);
    node* c=new node(30);
    node* d=new node(40);
    node* e=new node(50);  
    node* f=new node(60);
    node* g=new node(70);
    node* h=new node(80);
    
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    g->next=h;
    node* ans=a;
    ans=listnode(ans);
    display(ans);
}