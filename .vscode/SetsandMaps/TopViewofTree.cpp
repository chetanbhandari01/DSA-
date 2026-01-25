#include<iostream>
#include<unordered_map>
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

void topview(Node*root){
    unordered_map<int,int>m;  //level ,root->val
    queue< pair <Node*,int > >q;  //root,level
    pair<Node* ,int> r;
    r.first=root;
    r.second=0;
    q.push(r);
    while(q.size()>0 ){
        Node* temp=(q.front().first);
        int level = (q.front().second);
        q.pop();
        if(m.find(level)==m.end()){  //level nahi mili tu add karo
            m[level]=temp->val;
        }
        if(temp->left !=NULL){
            pair <Node*,int>p;
            p.first=temp->left;
            p.second=level-1;
            q.push(p);
        }
        if(temp->right!=NULL){
            pair<Node* ,int>p;
            p.first=temp->right;
            p.second=level+1;
            q.push(p);
        }
    }
    int minlevel=INT_MAX;
    int maxlevel=INT_MIN;
    for(auto x:m){
        int level=x.first;
        minlevel=min(minlevel,level);
        maxlevel=max(maxlevel,level);
    }
    for(int i=minlevel;i<=maxlevel;i++){
        cout<<m[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int>v={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7};
    Node* root =Construct(v);
    topview(root);
}