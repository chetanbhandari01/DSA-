#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* BST(Node* root,int val){
    if(root==NULL) return NULL;
    else if(root->val==val) return root;
    else if(root->val > val) return BST(root->left,val);
    else return BST(root->right,val);
}
void displayTree(Node*root){
    if(root==NULL)return ;
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
    Node* ans = BST(a,8);
    displayTree(ans);

}