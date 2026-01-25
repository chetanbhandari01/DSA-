#include<iostream>
using namespace std;
class node{
public:
    int val;
    node*next;
    node*prev;   //one more add that store previous address
    node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
    
};
class DLL{
public:
    node*head;
    node*tail;
    int size;
    DLL(){
        head=tail=NULL;
        size=0;
    }
    void insertAttail(int val){
        node*temp=new node(val);
        if(size==0) head=tail=temp ;
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        size++;
    }
    void insertAthead(int val){
        node*temp=new node(1);
        if(size==0) head=tail=temp;
        else {
            head->prev=temp;
            temp->next=head;
            head=temp;
        }
        size++;
    }
    void insertATidx(int idx,int val){
        if(idx<0 || idx>size) cout<<"invalid index"<<endl;
        else if(idx==0) insertAthead(val);
        else if(idx==size) insertAttail(val);
        else {
            node*t=new node(val);
            node*temp=head;
            for(int i=1;i<idx-1;i++){
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            t->next->prev=t;
            t->prev=temp;
            size++;
        }
    }
    void deleteAthead(){
        if(size==0){
            cout<<"empty list";
            return ;
        }
        head=head->next;
        if(head!=NULL)head->prev=NULL;
        if(head==NULL) tail=NULL;
        size--;
    }
    void deleteAttail(){
        if(size==0){
            cout<<"list is empty";
            return;
        }
        else if(size==1){
            deleteAthead();
            return ;
        }    
        node*temp=tail->prev;
        temp->next=NULL;
        tail=temp;
        size--;    
    }
    void deleteAtidx(int idx){
        if(idx<0 ||idx>=size){
            cout<<"invalid index ";
            return ;
        }
        else if(size==0){
            cout<<"list is empty ";
            return ;
        }
        else if(idx==0) return deleteAthead();
        else if(idx==size-1) return deleteAttail();
        else {
            if(idx<size/2){
                node*temp=head;
                for(int i=1;i<idx-1;i++){
                    temp=temp->next;
                }
                temp->next=temp->next->next;
                temp->next->prev=temp;
                size--;
            }
            else{ //idx>=size/2
                node*temp=tail;
                for(int i=1;i<size-idx;i++){
                    temp=temp->prev;
                }
                temp->prev=temp->prev->prev;
                temp->prev->next=temp;
                size--;
            }
        }
    }
    int getIdx(int idx){
        if(idx<0 ||idx>=size){
            cout<<"invalid idx ";
            return -1 ;
        }
        else if(idx==0) return head->val;
        else if(idx==size-1) return tail->val;
        else {       
            if(idx<size/2){  //for optimize solution
                node*temp=head;
                for(int i=1;i<idx;i++){
                    temp=temp->next;
                }
                return temp->val;
            }
            else{  //idx>size/2
                node*temp=tail;
                for(int i=1;i<size-idx;i--){
                    temp=temp->prev;
                }
                return temp->val;
            }
        }
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
    //10 20 30 40 50
    DLL ll;
    ll.insertAttail(10);
    ll.insertAttail(20);
    ll.insertAttail(30);
    ll.insertAttail(40);
    ll.insertAttail(50);
    ll.display();
    ll.insertAttail(60);
    ll.display();
    ll.insertATidx(3,100);
    ll.display();
    ll.deleteAtidx(5);  //delete at 4 idx
    ll.display();
    cout<<ll.getIdx(5);
}