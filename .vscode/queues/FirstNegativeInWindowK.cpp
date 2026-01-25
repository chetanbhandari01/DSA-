#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int> v={0,2,-3,-5,6,-7,3,-1,6,-5};
    int k=3;
    int n=v.size();
    vector<int>ans;
    queue<int>q;
    for(int i=0;i<n-k+1;i++){
        if(v[i]<0){
            q.push(i);
        }
    }
    int i=0;
    while(i <=n-k){
        while( q.size()>0 && q.front() < i) q.pop();
        if(q.size()==0 || q.front() >=i+k) ans.push_back(0);
        else ans.push_back(v[q.front()]);
        i++;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    
    // *********** Brute force ***************
    // vector<int> v={0,2,-3,-5,6,-7,3,-1,6,-5};
    // int k=3;
    // vector<int>ans(8,0);
    // for(int i=0;i<8;i++){
    //     for(int j=i;i<i+k;j++){
    //         if(v[j]<0) {
    //             ans[i]=v[j];
    //             break;
    //         }
    //     }
    // }
    // for(int i=0;i<8;i++){
    //     cout<<ans[i]<<" ";
    // }
}