#include<iostream>
using namespace std;
class node{
public:
    int val;
    node* next;
    node(int val){
        this->val=val;
        this->next=NULL;
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
    node* mergelist(node*a,node*b){
        node*c=new node(100);
        node*temp=c;
        while(a!=NULL && b!=NULL){
            if(a->val <= b->val){
                temp->next=a;
                a=a->next;
                temp=temp->next;
            }
            else{
                temp->next=b;
                b=b->next;
                temp=temp->next;
            }
        }
        if(a==NULL) temp->next=b;
        else temp->next=a;
        return c->next;
    }
    void display(node*c){
        while(c!=NULL){
            cout<<c->val<<" ";
            c=c->next;
        }
    }
};
int main(){
    linkedlist ll;
    node*a=new node(1);
    node*b=new node(2);
    node*c=new node(3);
    node*d=new node(4);

    node*e=new node(1);
    node*f=new node(6);
    node*g=new node(7);
    node*h=new node(8);
    node*i=new node(9);
    a->next=b;
    b->next=c;
    c->next=d;
    
    e->next=f;
    f->next=g;
    g->next=h;
    h->next=i;
    node*result=ll.mergelist(a,e);
    ll.display(result);

}