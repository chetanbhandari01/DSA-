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
node *detectCycle(node *head) {
    node*slow=head;
    node*fast=head;
    bool flag=false;
    while(fast!=NULL &&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) {
            flag =true;
            break;
        }
    }
    if(flag==false) return NULL;
    else{
        node*temp=head;
        while(slow!=temp){
            slow=slow->next;
            temp=temp->next;
        }
        return slow;
    }
}
void displayCycle(node* start) {
    if (start == NULL) {
        cout << "No cycle found" << endl;
        return;
    }

    node* temp = start;
    do {
        cout << temp->val << " ";
        temp = temp->next;
    } while (temp != start);
    cout << endl;
}
int main(){
    node* a=new node(10);  
    node* b=new node(20);
    node* c=new node(30);
    node* d=new node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=a;
    node* cycleStart = detectCycle(a);
    if (cycleStart != NULL) {
        cout << "Cycle detected at node with value: " << cycleStart->val << endl;
        cout << "Cycle elements: ";
        displayCycle(cycleStart);
    } else {
        cout << "No cycle detected" << endl;
    }
    displayCycle(cycleStart);
    
}
