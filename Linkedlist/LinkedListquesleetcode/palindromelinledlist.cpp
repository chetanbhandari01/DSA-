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
    bool isPalindrome(node* head) {   
        node*slow=head;
        node*fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        node*newhead=reverselist(slow->next);
        node* a=head;
        node* b=newhead;
        while(b!=NULL){
            if(a->val != b->val) return false ;
            a=a->next;
            b=b->next;
        }
        return true;
    }
};
int main(){
    linkedlist ll;
    node* a=new node(10);  
    node* b=new node(20);
    node* c=new node(20);
    node* d=new node(10);
    a->next=b;
    b->next=c;
    c->next=d;
    bool result=ll.isPalindrome(a);
    cout<<result;
    //ll.display(result);
}
