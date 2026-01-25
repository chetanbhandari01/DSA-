#include<iostream>
using namespace std;
class node{   //user defined data type
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
    void insertAtEnd(int val){
        node* temp=new node(val);
        if(size==0) head = tail= temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        size++;
    }
    void deleteAtHead(){
        if(size==0) {
            cout<<"list is empty ";
            return ;
        }
        head=head->next;
        size--;
    }
    void deleteAtTail(){
        if(size==0) {
            cout<<"list is empty ";
            return ;
        }
        node* temp=head;
        while(temp->next !=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        size--;
    }
    void deleteAtIdx(int idx){
        if(size==0) {
            cout<<"list is empty ";
            return ;
        }
        else if(idx<0 ||idx>=size){
            cout<<"invalid index";
            return ;
        }
        else if(idx==0) return deleteAtHead();
        else if(idx==size-1) return deleteAtTail();
        else {
            node* temp=head;
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
            size--;
        }
    }
    void display(){
        node* temp=head;
        while(temp !=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    Linkedlist ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.insertAtEnd(30);
    ll.insertAtEnd(40);
    ll.insertAtEnd(50);
    ll.insertAtEnd(60);
    ll.display();
    cout<<endl;
    //ll.deleteAtHead();
    //ll.display();
    //ll.deleteAtTail();
    //cout<<endl;
    //ll.display();
    
    ll.deleteAtIdx(3);
    ll.display();
}