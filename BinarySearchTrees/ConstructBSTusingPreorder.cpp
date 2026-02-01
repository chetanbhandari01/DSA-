#include<iostream>
#include<vector>
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
Node* insertBST(Node*root,int val){
    if(root==NULL) return new Node(val);
    else if(root->val >val){
        if(root->left ==NULL){
            Node*a=new Node(val);
            root->left=a;
        }
        else insertBST(root->left,val);
    }
    else {
        if(root->right ==NULL){
            Node* a=new Node(val);
            root->right=a;
        }
        else insertBST(root->right,val);
    }
    return root;
}
Node*ConstructBST(vector<int>&preorder){
    Node*root=new Node(preorder[0]);
    for(int i=1;i<preorder.size();i++){
        insertBST(root,preorder[i]);
    }
    return root;
}
void displayTree(Node*root){
    if(root==NULL) return ;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}
int main(){
    vector<int>preorder={2,3,1,4,5,6};
    Node*result=ConstructBST(preorder);
    displayTree(result);
}