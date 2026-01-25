#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>>closetorigin(vector<vector<int>>&arr,int k){
    int n=arr.size();
    priority_queue<pair<int,vector<int>>>pq;
    for(vector<int>v:arr){
        int x=v[0];
        int y=v[1];
        int dis = x*x +y*y;
        pq.push({dis,v});
        if(pq.size()>k) pq.pop();
    }
    vector<vector<int>>ans;
    while(pq.size()>0){
        vector<int>v=pq.top().second;
        ans.push_back(v);
        pq.pop();
    }
    return ans;
}
int main(){
    vector<vector<int>>v={{2,2},{1,2},{4,3}};
    vector<vector<int>>ans=closetorigin(v,1);
    for(vector<int>vv:ans){
        cout<<vv[0]<<" "<<vv[1];
    }
}