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
void Trim(Node* root,int lo,int hi){
    if(root==NULL) return ;
    while(root->left !=NULL){
        if(root->left->val < lo){
            root->left=root->left->right;
        }
        else if(root->left->val > hi){
            root->left=root->left->left;
        }
        else break;
    }
    while(root->right !=NULL){
        if(root->right->val > hi){
            root->right = root->right->left;
        }
        else if(root->right->val <lo){
            root->right=root->right->right;
        }
        else break;
    }
    Trim(root->left,lo,hi);
    Trim(root->right,lo,hi);
}
Node* trimBST(Node* root,int lo,int hi){
    Node* dummy = new Node(INT_MAX);
    dummy->left=root;
    Trim(dummy,lo,hi);
    return dummy->left;
}
void display(Node* root){
    if(root==NULL)return ;
    display(root->left);
    cout<<root->val<<" ";
    display(root->right);
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
    Node* result=trimBST(a,10,13);
    display(result);
}