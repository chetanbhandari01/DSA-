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
int main(){
    node* a=new node(10);  //
    node* b=new node(20);
    node* c=new node(30);
    node* d=new node(40);
    //forming lisked list
    a->next=b;
    b->next=c;
    c->next=d;
    cout<<a->val<<endl; //a ki value print hogi
    cout<<a->next->next->val <<endl;  //a ka next=b hai  b ka next=c  c ki value print hogi
    node* temp=a;  //temp ek dhaba hai usme a ki address store hai
    while(temp !=NULL){
        cout<<temp->val<<" ";  //temp=10  20  30  40
        temp=temp->next;      //temp= a ke next me 'b' ka address hai 
    }

}