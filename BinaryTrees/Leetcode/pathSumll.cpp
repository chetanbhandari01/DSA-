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
void helper(Node*root, vector<vector<int>>ans,vector<int>v,int target){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        if(root->val ==target){
            v.push_back(root->val);
            ans.push_back(v);
        }
    }
    v.push_back(root->val);
    helper(root->left,ans,v,target-(root->val));
    helper(root->right,ans,v,target-(root->val));
}
vector<vector<int>> pathSum(Node*root ,int target){
    vector<vector<int>>ans;
    vector<int>v;
    helper(root,ans,v,target);
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
    vector<vector<int>>v(pathSum(a,5));
    for(int i=0;i<v.size();i++){  //print will not
        cout<<v[0][1];
    }
}