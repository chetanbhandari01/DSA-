//61
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
    node* rotateRight(node* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        node*temp=head;
        node*tail=NULL;
        int len=0;  //finding lenght of list
        while(temp!=NULL){
            if(temp->next==NULL) tail=temp;
            temp=temp->next;
            len++;
        }
        k=k%len;  //if k>n 12 rotation are same as 2 means 12%5=2
        if(k==0) return head;
        //i have to place temp at( n-k)th position
        temp=head;
        for(int i=1;i<len-k;i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
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
    node*c=new node(3);
    node*d=new node(4);
    a->next=b;
    b->next=c;
    c->next=d;
    node*result=a;
    int k=2;
    result=ll.rotateRight(result,k);
    ll.display(result);
}