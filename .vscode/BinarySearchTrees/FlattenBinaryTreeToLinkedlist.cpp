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

void flattenlist(Node*root){
    if(root==NULL) return ;
    Node* curr=NULL;
    while(curr!=NULL){
        if(curr->left!=NULL){
            Node* r=curr->right;//saving right node
            curr->right=curr->left;
            //predecessor
            Node* pred=curr->left;
            while(pred->right!=NULL) pred=pred->right;
            //link
            pred->right=r;
            curr=curr->left;
        }
        else curr=curr->right;
    }
    Node* temp=root;
    while(temp!=NULL){
        temp->left=NULL;
        temp=temp->right;
    }
}
void displayLinkedlist(Node* root){
    Node*temp=root;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->right;
    }
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
    flattenlist(a);
    displayLinkedlist(a);
}