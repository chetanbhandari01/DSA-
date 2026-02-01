#include<iostream>
#include<vector>
using namespace std;
class node{
public:
    int val;
    node* next;
    node*prev;
    node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class Deque{
public:
    node*head;
    node*tail;
    int size;
    Deque(){
        head=tail=NULL;
        size=0;
    }
    void pushBack(int val){
        node* temp = new node(val);
        if(size==0) head=tail=temp;
        else {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        size++;
    }
    void pushFront(int val){
        node*temp=new node(val);
        if(size==0) head=tail=temp;
        else{
            head->prev=temp;
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void popFront(){
        if(size==0){
            cout<<"list is Empty"<<endl;
            return;
        }
        head=head->next;
        if(head) head->prev=NULL;
        if(head==NULL) tail=NULL;
        size--;
    }
    void popBack(){
        if(size==0){
            cout<<"list is Empty"<<endl;
            return;
        }
        else if(size==1){
            popFront();
            return ;
        }
        node*temp =tail->prev;
        temp->next=NULL;
        tail=temp;
        size--;
    }
    int front(){
        if(size==0) {
            cout<<"Queue is Empty ";
            return -1;
        }
        return head->val;
    }
    int back(){
        if(size==0) {
            cout<<"Queue is Empty ";
            return -1;
        }
        return tail->val;
    }
    void display(){
        node*temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Deque dq;
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushFront(30);
    dq.pushBack(40);
    dq.pushBack(50); 
    dq.display();
    dq.popBack();
    dq.display();
}