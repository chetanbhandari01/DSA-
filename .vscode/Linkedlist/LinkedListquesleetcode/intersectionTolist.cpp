//160
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
node *getIntersectionNode(node *headA, node *headB) {
    node* tempA=headA;
    node* tempB=headB;
    int lenA=0;
    int lenB=0;
    while(tempA !=NULL){
        lenA++;
        tempA=tempA->next;
    } 
    while(tempB!=NULL){
        lenB++;
        tempB=tempB->next;
    }
    tempA=headA;  //phir se head pe lana 
    tempB=headB;  //important hai
    if(lenA>lenB){
        int diff=lenA-lenB;
        for(int i=1;i<=diff;i++){
            tempA=tempA->next;
        }
        while(tempA!=tempB){  //checking address`s
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
    else{
        int diff=lenB-lenA;
        for(int i=1;i<=diff;i++){
            tempB=tempB->next;
        }
        while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempB;
    }
}
void display(node*tempA){
    while(tempA !=NULL){
        cout<<tempA->val<<" ";
        tempA=tempA->next;
    }
}
int main(){
    node* a=new node(10);  
    node* b=new node(20);
    node* c=new node(30);
    node* d=new node(40);
    
    node* e=new node(1);  
    node* f=new node(2);
    node* g=new node(3);
    node* h=new node(40);
    node* i=new node(50);

    a->next=b;
    b->next=c;
    c->next=d;

    e->next=f;
    f->next=g;
    g->next=h;
    h->next=i;

    i->next=c;  //intersection

    node* headA=a;
    node* headB=e;
    headA=getIntersectionNode(headA,headB);
    display(headA);
}