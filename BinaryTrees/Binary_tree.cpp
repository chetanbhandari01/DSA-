#include <iostream>
#include <queue>    
#include <vector>
using namespace std;

class Node{
public:
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val = val;
        this->right = NULL;
        this->left  =NULL;
    }
};

Node* insert(Node*root,int val){
    Node* newval = new Node(val);
    
    if(root==NULL) return newval;
    
    queue<Node*>pq;
    pq.push(root);
    
    while(pq.size() >0){
        Node* temp = pq.front();
        pq.pop();
        
        if(temp->left ==NULL){
            temp->left = newval;
            return root;
        }
        else{
            pq.push(temp->left);
        }
        if(temp->right ==NULL){
            temp->right = newval;
            return root;
        }
        else{
            pq.push(temp->right);
        }
    }
    return root;
}
Node* copy(Node*root){
    if(root==NULL) return NULL;
    Node* newroot = root;
    newroot->left = copy(root->left);
    newroot->right = copy(root->right);
    
    return newroot;
}
void display(Node*root){   // level wise print
    if(root==NULL) return;
    queue<Node*>pq;
    pq.push(root);
    while(pq.size() >0){
        Node*temp = pq.front();
        pq.pop();
        cout<<temp->val<<" ";
        if(temp->left != NULL) pq.push(temp->left);
        if(temp->right != NULL) pq.push(temp->right);
    }
}
int main() {
	Node* root = NULL;
	for(int i=0;i<5;i++){
	    int a;
	    cin>>a;
	    root = insert(root,a);
	}
	display(root);
	Node * newroot = copy(root);
	cout<<endl;
	display(newroot);
}
