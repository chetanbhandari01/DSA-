#include<iostream>
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
int sum=0;
void Reverseinorder(Node*root){
    if(root==NULL) return ;
    Reverseinorder(root->right);
    root->val +=sum;
    sum=root->val;
    Reverseinorder(root->left);
}
Node* BSTtoGst(Node*root){
    Reverseinorder(root);
    return root;
}
void displayTree(Node*root){
    if(root==NULL) return ;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}
int main(){
    Node* a = new Node(10);
    Node* b= new Node(8);
    Node* c= new Node(15);
    Node* d=new Node(5);
    Node* e =new Node(13);
    Node* f =new Node(18);
    a->left=b;
    a->right=c;
    b->left=d;
    c->left=e;
    c->right=f;
    Node* ans=BSTtoGst(a);
    displayTree(ans);
}