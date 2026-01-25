//206
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
class linkedlist{
public:
    node*head;
    node*tail;
    int size;
    linkedlist(){
        head=tail=NULL;
        size=0;
    }
    ////iterative way
    node*reverselist(node*head){
        if(head==NULL && head->next==NULL) return head;
        node*prev=NULL;
        node*curr=head;
        node*Next=NULL; 
        while(curr!=NULL){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;
        }
        return prev;
    }
    ////recurvise way
    // node*reverselist(node*head){
    //     if(head==NULL || head->next==NULL) return head;
    //     node*newhead=reverselist(head->next);
    //     head->next->next=head;
    //     head->next=NULL;
    //     return newhead;
    // }
    void display(node* head){
        node* temp=head;
        while(temp !=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    linkedlist ll;
    node* a=new node(10);  
    node* b=new node(20);
    node* c=new node(30);
    node* d=new node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    node*result=ll.reverselist(a);
    ll.display(result);
}