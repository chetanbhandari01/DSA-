//important 
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
bool exists(Node*root ,Node*target){
    if(root==NULL) return false;
    if(root==target) return true;
    return exists(root->left,target) || exists(root->right,target);
}
Node*Ancestor(Node*root,Node*p,Node*q){
    if(root==NULL) return root;
    else if(exists(root->left,p) && exists(root->right ,q)) return root;
    else if(exists(root->left,q) && exists(root->right,p)) return root;
    else if(exists(root->left,p) && exists(root->left ,q)) return Ancestor(root->left,p,q);
    else return Ancestor(root->right ,p,q);
}

int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    Node* p=new Node(4);
    Node* q=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    cout<<Ancestor(a,p,q);
    
}