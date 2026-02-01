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

int path(Node*root,int& maxsum){
    if(root==NULL) return 0;
    int l= path(root->left,maxsum);
    int r= path(root->right,maxsum);
    int temp=max(max(l,r)+root->val ,root->val);
    int ans = max(temp,l+r+root->val);
    maxsum=max(ans,maxsum);
    return temp;
}
int maxpath(Node*root){
    int sum=INT_MIN;
    path(root,sum);
    return sum;
}
int main(){
    Node* a=new Node(-1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);
    Node* h=new Node(8);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    g->right=h;
    cout<<maxpath(a);
}