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
class Queue{
public: 
    node*head;
    node*tail;
    int size;
    Queue(){
        head=tail=NULL;
        size=0;
    }
    void push(int val){  //insert at tail function means pichase insert karoga
        node*temp=new node(val);
        if(size==0) head = tail = temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void pop(){  //delete at head
        if(size==0) {
            cout<<"Queue is Empty ";
            return;
        }
        head=head->next;
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
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50); 
    q.display();
    q.pop();
    q.display();
}