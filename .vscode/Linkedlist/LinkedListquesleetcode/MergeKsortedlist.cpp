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
    node* mergeTwoLists(node* list1, node* list2) {     
        node*c=new node(100); //c->100
        node*tempC=c;
        while(list1!=NULL && list2!=NULL){
            if(list1->val <=list2->val){
                tempC->next=list1; 
                list1=list1->next;
                tempC=tempC->next;
            }
            else{
                tempC->next=list2;
                list2=list2->next;
                tempC=tempC->next;
            }
        }
        if(list1==NULL){
            tempC->next=list2;
        }
        else{  //list2==null hai
            tempC->next=list1;
        }
        return c->next;     
    }

    node* mergeKLists(vector<node*>& arr) {
        if(arr.size()==0) return NULL;
        while(arr.size()>1){
            node* a=arr[0];
            arr.erase(arr.begin());  //aage se delete karna
            node* b=arr[0];
            arr.erase(arr.begin());
            node*c=mergeTwoLists(a,b);
            arr.push_back(c);
        }
        return arr[0];
    }
    void display(node*arr){
        while(arr!=NULL){
            cout<<arr->val<<" ";
            arr=arr->next;
        }
    }
};
int main(){
    linkedlist ll;
    node*a=new node(1);
    node*b=new node(2);
    node*c=new node(1);
    node*d=new node(4);
    node*e=new node(5);
    node*f=new node(4);
    node*g=new node(7);
    node*h=new node(8);
    node*i=new node(9);
    a->next=b;
    
    c->next=d;
    d->next=e;
    
    f->next=g;
    g->next=h;
    h->next=i;
    vector<node*> v={a,c,f};
    node*result=ll.mergeKLists(v);
    ll.display(result);
}