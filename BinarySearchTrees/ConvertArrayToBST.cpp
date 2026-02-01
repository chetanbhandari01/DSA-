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
Node* helper(vector<int>&arr,int lo,int hi){
    if(lo > hi) return NULL;
    int mid=lo+(hi-lo)/2;
    Node*root=new Node(arr[mid]);
    root->left=helper(arr,lo,mid-1);
    root->right=helper(arr,mid+1,hi);
    return root;
}
Node* arrayToBST(vector<int>&arr){
    int n=arr.size();
    return helper(arr,0,n-1);
}
void displayTree(Node*root){
    if(root==NULL) return ;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}
int main(){
    vector<int>arr={1,2,3,4,5,6,7};
    Node*result=arrayToBST(arr);
    displayTree(result);
}