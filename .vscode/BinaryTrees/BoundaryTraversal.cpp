#include<iostream>
#include<queue>
using namespace std;
class Node{
public:
    int val;
    Node*left=NULL;
    Node*right=NULL;
    Node(int val){
        this->val=val;
        this->left=left;
        this->right=right;
    }
};
Node* Construct(vector<int>&arr){
    int n=arr.size();
    queue<Node*>q;
    Node* root=new Node(arr[0]);
    q.push(root);
    int i=1;
    int j=2;
    while(q.size()>0 && i<n){
        Node* temp=q.front();
        q.pop();
        Node* l;  //l =left
        Node* r;  //r=right
        if(arr[i]!=INT_MIN) l =new Node(arr[i]); // 
        else l=NULL;
        if(j!=n && arr[j]!=INT_MIN) r=new Node(arr[j]);  //j!=n for array end condition
        else r=NULL;
        
        temp->left=l;
        temp->right=r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i += 2;
        j += 2;
    }
    return root;
}
void LeftBoundry(Node* root){
    if(root==NULL) return ;
    if(root->left ==NULL && root->right==NULL) return ;
    cout<<root->val<<" ";
    LeftBoundry(root->left);
    if(root->left==NULL) LeftBoundry(root->right);
}
void LeafNode(Node * root){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) cout<<root->val<< " ";
    LeafNode(root->left);
    LeafNode(root->right);
}
void RightBoundary(Node*root){   //reverse chaiye iseliye call baad me kiya
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return ;
    RightBoundary(root->right);
    if(root->right==NULL) RightBoundary(root->left);
    cout<<root->val<<" ";
}
int main(){
    vector<int>v = {
    1, NULL, 2, NULL, 3, NULL, 4, NULL, NULL
    };

    Node* root=Construct(v);
    LeftBoundry(root);
    LeafNode(root);
    RightBoundary(root->right); //left root liya hai
}