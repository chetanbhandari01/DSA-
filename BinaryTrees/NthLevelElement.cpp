//DFS
#include<iostream>
#include<algorithm>
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
void NthLevel(Node* root,int level,int curr){
    if(root==NULL) return ;
    if(curr==level){
        cout<<root->val<<" ";
        return ;  //optimize 
    }
    NthLevel(root->left ,level,curr+1);
    NthLevel(root->right,level,curr+1);
    
}

// void NthLevelReverse(Node* root,int level,int curr){
//     if(root==NULL) return ;
//     if(curr==level){
//         cout<<root->val<<" ";
//         return ;  //optimize 
//     }
//     NthLevelReverse(root->right ,level,curr+1);
//     NthLevelReverse(root->left,level,curr+1);
    
// }

int levels(Node*root){
    if(root==NULL) return 0;
    return 1+max(levels(root->left),levels(root->right));
}

void Levelorder(Node*root){
    int n=levels(root);
    for(int i=1;i<=n;i++){
        NthLevel(root,i,1);
        cout<<endl;
    }
    return;
}

// void LevelorderRev(Node*root){
//     int n=levels(root);
//     for(int i=1;i<=n;i++){
//         NthLevelReverse(root,i,1);
//         cout<<endl;
//     }
//     return;
// }
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
    Levelorder(a);
    // LevelorderRev(a);
}