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
void display(node* head){
    node* temp=head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
void insertAtEnd(node* head,int val){
    node* t=new node(val);
    while(head->next !=NULL) head=head->next;
    head->next=t;
}
int main(){
    node* a = new node(10);
    node* b = new node(20);
    node* c = new node(30);
    a->next=b;
    b->next=c;
    insertAtEnd(a,40);
    display(a);
}