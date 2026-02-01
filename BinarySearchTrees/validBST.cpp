#include<iostream>
#include<vector>
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
void inorder(Node* root,vector<int>&ans){
    if(root==NULL) return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
bool isvalidBST(Node*root){
    vector<int>ans;
    inorder(root,ans);
    bool flag=true;
    for(int i=1;i<ans.size();i++){
        if(ans[i-1] >=ans[i] ) flag =false;
    }
    return true;
}
int main(){
    Node* a = new Node(10);
    Node* b= new Node(8);
    Node* c= new Node(15);
    Node* d=new Node(5);
    Node* e =new Node(13);
    Node* f =new Node(18);
    a->left=b;
    a->right=c;
    b->left=d;
    c->left=e;
    c->right=f;
    cout<<isvalidBST(a);

}