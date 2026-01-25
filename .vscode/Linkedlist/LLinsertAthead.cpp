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
class Linkedlist{
public:
    node* head;
    node* tail;
    int size;
    Linkedlist(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void insertAtTail(int val){  //this perviouly done insert at end
        node* temp=new node(val);
        if(size==0) head =tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void insertathead(int val){   //insert at head
        node* temp=new node(val);
        if(size==0) head =tail=temp;
        else {
            temp->next=head;
            head=temp;
        }
        size++;
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
    Linkedlist ll;
    ll.insertAtTail(20);
    ll.insertAtTail(40);
    ll.insertAtTail(60);
    //
    ll.insertathead(50);   //insert at head
    ll.display();

}