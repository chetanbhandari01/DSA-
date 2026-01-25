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
    node* partition(node* head, int x) {
        node*temp=head;
        node* lo=new node(100);
        node* hi=new node(100);
        node* templo=lo;
        node* temphi=hi;
        while(temp!=NULL){
            if(temp->val <x){
                templo->next=temp;
                templo=templo->next;
                temp=temp->next;
            }
            else { //temp->val=x
                temphi->next=temp;
                temphi=temphi->next;
                temp=temp->next;
            }
        }
        templo->next=hi->next;   //templo ke next me hi ka next (hi->100->next lena)
        temphi->next=NULL;   //last me hoga add NULL
        return lo->next;  //lo ->100->next ye print karna
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
    node*result=ll.partition(a,50);
    ll.display(result);
}