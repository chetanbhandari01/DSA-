#include<iostream>
using namespace std;
class node{
public:
    int val;
    node*next=next;
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
    node* deleteDuplicates(node* head) {
        if(head==NULL || head->next==NULL) return head;
        node*a=head;
        node*b=head->next;
        while(b!=NULL){
            while(b!=NULL && a->val==b->val){
                b=b->next;
            }
            a->next=b;
            a=b;
            if(b!=NULL) b=b->next;
        }
        return head;
    }
    void display(node*head){
        while(head!=NULL){
            cout<<head->val<<" ";
            head=head->next;
        }
        
    }
};

int main(){
    linkedlist ll;
    node*a=new node(1);
    node*b=new node(2);
    node*c=new node(2);
    node*d=new node(3);
    a->next=b;
    b->next=c;
    c->next=d;
    node* result=a;
    result =ll.deleteDuplicates(result);
    ll.display(result);
}