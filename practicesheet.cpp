#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>
#include<stack>
#include<unordered_map>
using namespace std;
bool cmp(vector<int>&a,vector<int>&b){
        return a[1] > b[1];
    }
int main(){
    // string str="123";
    // reverse(str.begin(),str.end());
    // cout<<str<<endl;
    // int n=34;
    // int temp=n;
    // int rever=0;
    // while(n>0){
    //     temp=n%10;
    //     rever=rever*10+temp;
    //     n/=10;

    // }
    // cout<<rever;
    // vector<vector<int>>a={{1,2},{1,2},{4,3}};
    // cout<<a[2][0];

    // vector<string>strs={"01","101","001"};
    // int n=strs.size();
    // unordered_map<char,int>map;
    // for(auto s:strs){
    //     string binary=s;
    //     for(int i=0;i<binary.size();i++){
    //         map[binary[i]]++;
    //     }
    // }
    // for(auto x : map){
    //     cout<<x.first<<" "<<x.second<<endl;
    // }
    
    // string s="dea*";
    // //sort(s.begin(),s.end());
    // int n=s[3];
    // cout<<n;
    
    // for(char i='a';i<'z';i++){
        
    //     cout<<i<<" ";
    // }
    
    // vector<vector<int>>arr={{100,9},{2,10},{2,1}};
    // sort(arr.begin(),arr.end(),cmp);
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<2;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    // }
    
    char c='3';
    int n=c-'0';
    cout<<n;
}


// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// class Node{
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node(int val){
//         this->val=val;
//         this->left=NULL;
//         this->right=NULL;
//     }
// };
// int level(Node*root){
//     if(root==NULL) return 0;
//     int l=level(root->left);
//     int r=level(root->right);
//     int ans=1+max(l,r);
//     return ans;
// }
// void diameter(Node*root,int& maxdia){
//     if(root==NULL) return;
//     int dia = (level(root->left)+level(root->right));
//     maxdia=max(dia,maxdia);
//     diameter(root->left,maxdia);
//     diameter(root->right,maxdia);
//     return;
// }
// int main(){
//     Node* a=new Node(1);
//     Node* b=new Node(2);
//     Node* c=new Node(3);
//     Node* d=new Node(4);
//     Node* e=new Node(5);
//     Node* f=new Node(6);
//     Node* g=new Node(7);
//     Node* h=new Node(8);
//     a->left=b;
//     a->right=c;
//     b->left=d;
//     b->right=e;
//     c->left=f;
//     c->right=g;
//     g->right=h;
//     int maxdia=0;
//     diameter(a,maxdia);
//     cout<<maxdia;

// }