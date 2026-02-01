#include<iostream>
#include<algorithm>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
bool isSameTree(Node* p, Node* q) {
    if(p==NULL && q==NULL) return true;
    if(p==NULL && q!=NULL ) return false;
    if(p!=NULL && q==NULL) return false;

    if(p->val != q->val) return false;

    bool leftAns=isSameTree(p->left ,q->left);
    if(leftAns==false) return false;

    bool RightAns=isSameTree(p->right ,q->right);
    if(RightAns==false) return false;

    return true;
}
int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(1);
    Node* e=new Node(2);
    Node* f=new Node(3);
    
    a->left=b;
    a->right=c;
    d->left=e;
    d->right=f;
    cout<<isSameTree(a,d);
    
    
}