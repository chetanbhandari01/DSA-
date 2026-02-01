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
Node* build(vector<int>& inorder,int inlo,int inhi, vector<int>& postorder,int postlo,int posthi){
    if(postlo>posthi) return NULL;
    Node* root=new Node(postorder[posthi]);
    if(postlo==posthi) return root;
    int i=inlo;
    while(i<=inhi){
        if(inorder[i]==postorder[posthi]) break;
        i++;
    }
    int leftcount=i-inlo;
    int rightcount=inhi-i;
    root->left=build(inorder,inlo,i-1,postorder,postlo,postlo+leftcount-1);
    root->right=build(inorder,i+1,inhi,postorder,postlo+leftcount,posthi-1);
    return root;

}
Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n= postorder.size();
    return build(inorder,0,n-1,postorder,0,n-1);
}
void printing(Node*root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    printing(root->left);
    printing(root->right);
}
int main(){
    vector<int>v1={1,2,4,5,3,6,7};
    vector<int>v2={4,5,2,6,7,3,1};
    Node* root=buildTree(v2,v2);
    printing(root);
}