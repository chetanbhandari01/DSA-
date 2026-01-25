#include<iostream>
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
Node* inorder_pred(Node* root){ //inorder predecessor
    Node* pred=root->left;
    while(pred->right!=NULL){
        pred=pred->right;
    }
    return pred;
}
Node* deleteNode(Node*root,int key){
    if(root==NULL) return NULL;
    else if(root->val==key){
        //case 1 : 0 child node
        if(root->left==NULL && root->right==NULL){
            return NULL ; //6 remove karyche tar tya jagi null taka
        }
        //case 2 : 1 child node
        if(root->left ==NULL || root->right ==NULL){
            if(root->left != NULL) return root->left;
            else return root->right;
        }

        //case 3 : 2 child node
        if(root->left !=NULL && root->right!=NULL){
            Node*pred = inorder_pred(root);
            root->val=pred->val;
            root->left=deleteNode(root->left,pred->val);
        }
    }
    else if(root->val > key){
        root->left=deleteNode(root->left,key);
    }
    else if(root->val <key){
        root->right = deleteNode(root->right,key);
    }
    return root;
}
void displayTree(Node* root){
    if(root==NULL) return ;
    displayTree(root->left);
    cout<<root->val<<" ";
    displayTree(root->right);
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
    Node* result= deleteNode(a,8);
    displayTree(result);
}