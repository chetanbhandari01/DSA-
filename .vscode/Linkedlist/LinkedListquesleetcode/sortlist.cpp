//148
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
    node* mergelist(node*a,node*b){
        node* c=new node(100); 
        node* temp=c;  //same address c store
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val){
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
    node* sortList(node* head) {
        if(head==NULL || head->next==NULL) return head;
        //to find the left middle
        node* slow=head;
        node* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){  //f->n!=NULL are left mid
            slow=slow->next;
            fast=fast->next->next;
        }
        //new slow is at left middle
        node*a=head;
        node*b=slow->next;
        slow->next=NULL;
        a=sortList(a);
        b=sortList(b);
        node*c=mergelist(a,b);
        return c;
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
    node* a=new node(50);  
    node* b=new node(100);
    node* c=new node(30);
    node* d=new node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    node* result=ll.sortList(a);
    ll.display(result);

}