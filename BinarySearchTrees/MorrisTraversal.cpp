//inorder traversal
#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node*right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
vector<int>MorriesTraversal(Node*root){
    vector<int>inorder;
    Node*curr=root;
    while(curr!=NULL){
        if(curr->left !=NULL){ //find predecessor
            Node* pred=curr->left;
            while(pred->right!=NULL && pred->right !=curr){
                pred=pred->right;
            }
            if(pred->right==NULL){ //link
                pred->right=curr;
                curr=curr->left;
            }
            if(pred->right ==curr){ //unlink
                pred->right=NULL;
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }
        else {
            inorder.push_back(curr->val);
            curr=curr->right;
        }
    }
    return inorder;
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
    vector<int>result=MorriesTraversal(a);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}