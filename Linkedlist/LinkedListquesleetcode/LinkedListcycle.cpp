//141 linked list cycle  very famous question
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
bool hasCycle(node *head) {
    node*slow=head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}
int main(){
    node* a=new node(10);  
    node* b=new node(20);
    node* c=new node(30);
    node* d=new node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=b;
    node* ans=a;
    cout<<hasCycle(ans);
}
