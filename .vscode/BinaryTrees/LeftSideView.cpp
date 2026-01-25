#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    Node*left=NULL;
    Node*right=NULL;
    int val;
    Node(int val){
        this->left=left;
        this->right=right;
        this->val=val;
    }
};
int level(Node*root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}
void preorder(Node*root,vector<int>&ans,int level){
    if(root==NULL) return;
    ans[level]=root->val;
    preorder(root->right,ans,level+1);
    preorder(root->left,ans,level+1);
}
vector<int>leftview(Node*root){
    vector<int>ans(level(root),0);
    preorder(root,ans,0);
    return ans;
}
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

    vector<int>v=leftview(a);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}