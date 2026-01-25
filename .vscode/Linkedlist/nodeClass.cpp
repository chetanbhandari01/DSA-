#include<iostream>
using namespace std;
class node{   //linked list node
public:
    int val;
    node *next;
    node(int val){   //help constructor 
        this->val=val;
        this->next=NULL; //base address
    }
};
int main(){
    //10 20 30 40
    node a(10);  //by constructor
    node b(20);
    node c(30);
    node d(40);
    //forming linked list
    a.next=&b;
    b.next=&c;
    c.next=&d;
    //using a we are print b value
    cout<<(a.next)->val<<endl;  // same hai cout<<(*(a.next)).val<<endl;
    //a se c ki value
    cout<<((a.next)->next)->val<<endl;
    //a se d ki value
    cout<<(((a.next)->next)->next)->val<<endl;

    //using loop printing all values
    node temp=a;
    while(1){
        cout<<temp.val<<" ";
        if(temp.next == NULL) break;
        temp=*(temp.next);
    }
}