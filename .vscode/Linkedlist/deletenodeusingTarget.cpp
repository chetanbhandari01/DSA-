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
node* deletenode(node* head,int targetval){  
    if(head->val==targetval){
        head=head->next;
        return head;
    }
    node* temp=head;
    while(temp->next->val != targetval){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    return head;
}
void display(node* head){
    node* temp=head;
    while(temp !=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
int main(){
    node* a=new node(10);  
    node* b=new node(20);
    node* c=new node(30);
    node* d=new node(40);
    
    a->next=b;
    b->next=c;
    c->next=d;

    node* head=a;   //a node hai vah head ek node me hai
    display(head);   //displaying head
    cout<<endl;
    head = deletenode(head,20);  //
    display(head);
}