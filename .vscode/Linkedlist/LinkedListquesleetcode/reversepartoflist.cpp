//92
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
    node* reverselist(node*head){
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
    node* reverseBetween(node* head, int left, int right) {
        if(left==right) return head;
        node*temp=head;
        node*a=NULL;
        node*b=NULL;
        node*c=NULL; 
        node*d=NULL;
        int n=1;
        while(temp!=NULL){
            if(n==left-1) a=temp;
            if(n==left) b=temp;
            if(n==right) c=temp;
            if(n==right+1) d=temp;
            temp=temp->next;
            n++;
        }       
        if(a!=NULL) a->next=NULL;   //a to b-1 ek linked list
        c->next=NULL;  //b to c ko reverse karna
        c=reverselist(b);
        if(a!=NULL) a->next=c;
        b->next=d;
        if(a!=NULL) return head;  //
        return c;  //[3,5] l=1 and Right=2 this type testcase 
    }
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
    node* e=new node(50);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    node*result=ll.reverseBetween(a,2,4);
    ll.display(result);
}