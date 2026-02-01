#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<vector>
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
Node*first=NULL;//first node where infection start 
void find(Node*root,int start){
    if(root==NULL) return;
    if(root->val ==start) first=root;
    find(root->left,start);
    find(root->right,start);
}
void makeparent(Node*root ,unordered_map<Node*,Node*>&parent){
    if(root==NULL) return;
    if(root->left!=NULL) parent[root->left]=root;
    if(root->right!=NULL) parent[root->right]=root;
    makeparent(root->left,parent);
    makeparent(root->right,parent);
}
int amountTimeToinfect(Node*root,int start){
    find(root,start);
    unordered_map<Node*,Node*>parent;  //child ,parent
    makeparent(root,parent);
    unordered_set<Node*>isinfected; 
    isinfected.insert(first);
    queue<pair<Node* ,int>>q;  //root,level
    q.push({first,0});
    int maxlevel=0;
    while(q.size()>0){
        pair<Node*,int>p=q.front();
        q.pop();
        Node* temp=p.first;
        int level=p.second;
        maxlevel=max(maxlevel,level);
        if(temp->left!=NULL){
            if(isinfected.find(temp->left)==isinfected.end()){
                q.push({temp->left,level+1});
                isinfected.insert(temp->left);
            }
        }
        if(temp->right!=NULL){
            if(isinfected.find(temp->right)==isinfected.end()){
                q.push({temp->right,level+1});
                isinfected.insert(temp->right);
            }
        }
        if(parent.find(temp)!=parent.end()){
            if(isinfected.find(parent[temp])==isinfected.end()){
                q.push({parent[temp],level+1});
                isinfected.insert(parent[temp]);
            }
        }
    }
    return maxlevel;

}
int main(){
    vector<int>v={1,2,3,4,5,6,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    Node* root =Construct(v);
    cout<<amountTimeToinfect(root,3);
}