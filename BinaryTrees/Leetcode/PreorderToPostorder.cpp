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
Node* build(vector<int>& preorder,int prelo,int prehi, vector<int>& postorder,int postlo,int posthi){
    if(postlo>posthi) return NULL;
    Node* root=new Node(preorder[prelo]);
    if(postlo==posthi) return root;
    int i=postlo;
    while(i<=posthi){
        if(preorder[prelo+1]==postorder[i]) break;
        i++;
    }
    int leftcount=i-postlo;
    int rightcount=posthi-i;
    root->left=build(preorder,prelo+1,prelo+leftcount+1,postorder,postlo,i);
    root->right=build(preorder,prelo+leftcount+2,prehi,postorder,i+1,posthi-1);
    return root;
}
Node* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int n=preorder.size();
    return build(preorder,0,n-1,postorder,0,n-1);
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
    Node* root=constructFromPrePost(v2,v2);
    printing(root);
}