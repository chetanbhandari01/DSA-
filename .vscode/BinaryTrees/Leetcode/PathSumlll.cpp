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
void helper(Node*root,int sum,int count){
    if(root==NULL) return;
    if(root->val==sum)count++;
    helper(root->left,sum-(root->val),count);
    helper(root->right,sum-(root->val),count);
}
int pathSum(Node* root,int target){
    if(root==NULL) return 0;
    int count=0;
    helper(root,target,count);
    count += (pathSum(root->left,target)+pathSum(root->right,target));
    return count;
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
    cout<<pathSum(a,3);
}