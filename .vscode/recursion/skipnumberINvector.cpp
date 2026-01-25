#include<iostream>
#include<vector>
using namespace std;
void duplicate(vector<int>&ans,vector<int>&v,int idx,int ansidx){
    if(idx==v.size()){
        for(int i=0;i<ansidx;i++){
            cout<<ans[i];
        }
        return ;
    }
    if(ansidx==0 || ans[ansidx-1] !=v[idx]) {
        ans[ansidx]=v[idx];
        duplicate(ans,v,idx+1,ansidx+1);
    }
    else duplicate(ans,v,idx+1,ansidx);
}
int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    vector<int>ans(v.size());
    duplicate(ans,v,0,0);
}