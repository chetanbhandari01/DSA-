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

void displayTree(Node* root){
    if(root==NULL) return ;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}
int sum(Node* root){
    if(root==NULL) return 0;
    int LeftSum= sum(root->left);
    int RightSum= sum(root->right);
    int sum= root->val + LeftSum +RightSum;
    return sum;
}

int Size(Node* root){
    if(root==NULL) return 0;
    return 1+Size(root->left)+Size(root->right);
}

int MaxVal(Node* root){
    if(root==NULL) return INT_MIN; //0 be use kar sakte hai par positive value ke liye hoga
    int lmax=MaxVal(root->left);
    int Rmax=MaxVal(root->right);
    int maxval= max(root->val,max(lmax,Rmax));
    return maxval;
}
int productTree(Node*root){
    if(root==NULL) return 1;
    int Lproduct=productTree(root->left);
    int Rproduct=productTree(root->right);
    int product=root->val*Lproduct*Rproduct;
    return product;
}
int levelTree(Node*root){
    if(root==NULL) return 0;
    int level=1+max(levelTree(root->left),levelTree(root->right));
    return level;
}
int height(Node* node) {
    if(node==NULL) return -1;
    return 1+max(height(node->left),height(node->right));
}
//height means =level-1
int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    displayTree(a);
    cout<<endl;
    cout<<sum(a);
    cout<<endl;
    cout<<Size(a);
    cout<<endl;
    cout<<MaxVal(a);
    cout<<endl;
    cout<<productTree(a);
    cout<<endl;
    cout<<levelTree(a);
    cout<<endl;
    cout<<height(a);
}