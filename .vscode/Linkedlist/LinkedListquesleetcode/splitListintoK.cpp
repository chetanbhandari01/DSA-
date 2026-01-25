//725
#include<iostream>
#include<vector>
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
class linkedlist{
public:
    node*head;
    node*tail;
    int size;
    linkedlist(){
        head=tail=NULL;
        size=0;
    }
    vector<node*> splitListToParts(node* head, int k) {
        int n=0;
        node*temp=head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        //breaking the list into k lists
        vector<node*>ans;
        int size=n/k;
        int rem=n%k;
        temp=head;
        while(temp!=NULL){
            int s=size;
            if(rem>0) s++;
            rem--;
            node*c=new node(100);
            node*tempC=c;
            for(int i=1;i<=s;i++){
                tempC->next=temp;
                temp=temp->next;
                tempC=tempC->next;
            }
            tempC->next=NULL;
            ans.push_back(c->next);
        }
        if(ans.size()<k){
            int extra=k-ans.size();
            for(int i=1;i<=extra;i++){
                ans.push_back(NULL);
            }
        }
        return ans;
    }
    void display(node*head){
        node* temp=head;
        while(temp !=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
};
int main(){
    linkedlist ll;
    node* a=new node(10);  
    node* b=new node(20);
    node* c=new node(30);
    node* d=new node(40);
    node* e=new node(50);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    vector<node*>res=ll.splitListToParts(a,2);
    for(int i=0;i<res.size();i++){
        ll.display(res[i]);
        cout<<endl;
    }
}