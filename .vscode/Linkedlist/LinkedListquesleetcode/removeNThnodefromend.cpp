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
////this method in coding round 
// node* removeNthFromEnd(node* head, int n) {
//     int len=0;
//     node* temp=head;
//     while(temp != NULL){
//         len++;
//         temp=temp->next;
//     }
//     if(len==n){
//         head=head->next;
//         return head;
//     }
//     //nth from end =(len-n+1)th from start
//     int m=len-n+1;
//     int removeidx=m-1;  //the idx of node to be deleted
//     temp=head;
//     for(int i=1;i<=removeidx-1;i++){
//         temp=temp->next;
//     }
//     temp->next=temp->next->next;
//     return head;
// }

////interviewer should ask for another approach and best approach
node* removeNthFromEnd(node* head, int n) {
    node*slow=head;
    node*fast=head;
    //traverse fast to n+1 step
    for(int i=1;i<=n+1;i++){
        if(fast==NULL) return head->next;
        fast=fast->next;
    }
    //move slow and fast at same pace
    while(fast !=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    //now 
    slow->next=slow->next->next;
    return head;
}
void display(node*slow){
    while(slow !=NULL){
        cout<<slow->val<<" ";
        slow=slow->next;
    }
}
int main(){
    node* a=new node(10);  
    node* b=new node(20);
    node* c=new node(30);
    node* d=new node(40);
    
    a->next=b;
    b->next=c;
    c->next=d;
    node* ans=a;
    ans=removeNthFromEnd(a,2);
    display(ans);
}