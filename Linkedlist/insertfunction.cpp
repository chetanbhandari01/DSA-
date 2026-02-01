//insert anywhere in linkedlist
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
class linkedlist{
public:
    node* head;
    node* tail;
    int size;
    linkedlist(){
        head=tail=NULL;
        size=0;
    }
    void insertAthead(int val){
        node* temp=new node(val);
        if(size==0) head=tail=temp;
        else{
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void insertATtail(int val){
        node* temp=new node(val);
        if(size==0) head=tail=temp;
        else {
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void insertAtIdx(int idx,int val){
        if(idx<0 || idx>size) cout<<"Invaild index";
        else if(idx==0) insertAthead(val);
        else if(idx==size) insertATtail(val);
        else{
            node* t=new node(val);
            node* temp=head;
            for(int i=1;i<idx-1;i++){
                temp=temp->next;
            }
            t->next = temp->next;
            temp->next=t;
            size++;
        } 
    }
    void display(){
        node* temp=head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    linkedlist ll;
    ll.insertATtail(20);
    ll.insertATtail(40);
    ll.insertATtail(60);
    //
    ll.insertAthead(50);  
    ll.insertAtIdx(1,100); 
    ll.display();
}