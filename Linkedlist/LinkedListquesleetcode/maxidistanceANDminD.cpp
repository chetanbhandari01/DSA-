//2058
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
    vector<int>MaxMinDistance(node*head){
        int idx=1;
        int firstidx=-1;
        int lastidx=-1;
        //min
        int f=-1;
        int s=-1;
        int minD=INT_MAX;
        node* a = head;
        node* b = head->next;
        node* c = head->next->next;
        while(c!=NULL){
            if(b->val >a->val && b->val>c->val ||b->val<a->val && b->val < c->val){  //critical point
                if(firstidx==-1) firstidx=idx;  //for maxD first initial kiya
                else lastidx=idx;  //last ka idx lena 

                //for minimum distance
                f=s;
                s=idx;
                if(f!=-1){
                    int d=s-f;
                    minD=min(minD,d);
                }
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;
        }
        if(lastidx==-1) return {-1,-1};
        int maxD=lastidx-firstidx;
        return {minD,maxD};
    }
};
int main(){
    linkedlist ll;
    node* a=new node(1);
    node* b=new node(3);
    node* c=new node(2);
    node* d=new node(2);
    node* e=new node(3);
    node* f=new node(2);
    node* g=new node(2);
    node* h=new node(2);
    node* i=new node(7);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    f->next=g;
    g->next=h;
    h->next=i;
    vector<int> ans = ll.MaxMinDistance(a);
    cout<<"Minimum Distance: "<<ans[0]<<endl;
    cout<<"Maximum Distance: "<<ans[1]<<endl;

}