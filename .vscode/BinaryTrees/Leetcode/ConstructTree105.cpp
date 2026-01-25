//construct binary tree from preorder and inorder traversal
#include<iostream>
#include<algorithm>
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
Node* build(vector<int>& preorder,int prelo,int prehi, vector<int>& inorder,int inlo,int inhi){
    if(prelo > prehi) return NULL;
    Node* root=new Node(preorder[prelo]);
    if(prelo==prehi) return root;
    int i=inlo;
    while(i<=inhi){
        if(inorder[i]==preorder[prelo]) break;
        i++;
    }
    int leftcount = i-inlo;  //logic
    int rightcount = inhi-i;  //
    root->left =build(preorder, prelo+1, prelo+leftcount, inorder, inlo,i-1);//imp
    root->right =build(preorder, prelo+leftcount+1, prehi, inorder, i+1,inhi);
    return root;
}
Node* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n= preorder.size();
    return build(preorder,0,n-1,inorder,0,n-1);
}
void printing(Node*root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    printing(root->left);
    printing(root->right);
}
int main(){
    vector<int>v1={3,9,20,15,7};
    vector<int>v2={9,3,15,20,7};
    Node* root=buildTree(v2,v2);
    printing(root);
}