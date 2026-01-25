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
class Stack{
public:
    node*head;
    int size;
    Stack(){
        head=NULL;
        size=0;
    }
    void push(int val){
        node* temp=new node(val);
        temp->next=head;
        head=temp;
        size++;
    }
    void pop(){
        if(head==NULL){
            cout<<"stack empty "<<endl;
            return ;
        }
        head=head->next;
    }
    int top(){
        if(head==NULL){
            cout<<"stack is empty "<<endl;
            return -1;
        }
        return head->val;
    }
    void print(node*temp){
        if(temp==NULL) return ;
        print(temp->next);
        cout<<temp->val<<" ";
    }
    void display(){
        node*temp=head;
        print(temp);
        cout<<endl;
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.display();
    st.pop();
    st.display();
}