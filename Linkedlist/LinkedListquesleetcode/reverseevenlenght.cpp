//2074
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
    node*reversepart(node*head,int left,int right){
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
            n++;
            temp=temp->next;
        }
        if(a!=NULL) a->next=NULL;
        c->next=NULL;
        c=reverselist(b);
        if(a!=NULL) a->next=c;
        b->next=d;
        if(a!=NULL) return head;
        return c;
    }
    node* reverseEvenLengthGroups(node* head) {
        node*temp=head;
        int gap=1;
        while(temp!=NULL && temp->next!=NULL){
            int remlen=0;   //remaining lenght
            node*t=temp->next;
            for(int i=1;i<=gap+1 && t!=NULL;i++){
                t=t->next;
                remlen++;
            }
            if(remlen < gap+1) gap=remlen-1;
            if(gap%2 != 0) reversepart(temp,2,2+gap);
            gap++;
            for(int i=1;i<=gap && temp!=NULL ;i++){
                temp=temp->next;
            }
        }
        return head;
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
    node* f=new node(60);
    node* g=new node(70);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    node*res=ll.reverseEvenLengthGroups(a);
    ll.display(res);
}