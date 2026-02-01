#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class node{
public:
    int val;
    node* left=NULL;
    node* right=NULL;
    node(int val){
        this->left=left;
        this->right=right;
        this->val=val;
    }
};
void inorder(node*root,vector<int>&arr){
    if(root==NULL) return;
    inorder(root->right,arr);
    arr.push_back(root->val);
    inorder(root->left,arr);
}
void preorder(node*root,vector<int>&arr,int &i){
    if(root==NULL) return;
    root->val = arr[i++];
    preorder(root->left,arr,i);
    preorder(root->right,arr,i);
}
void levelorderprint(node*root){
    queue<node*>q;
    q.push(root);
    while(q.size()>0){
        node*temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    cout<<endl;
}
void print(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    node* a=new node(10);
    node* b=new node(5);
    node* c=new node(16);
    node* d=new node(1);
    node* e=new node(8);
    node* f=new node(12);
    node* g=new node(20);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    vector<int>arr;
    inorder(a,arr); //in array sort order
    levelorderprint(a);
    int i=0;
    preorder(a,arr,i);
    levelorderprint(a);
    
}