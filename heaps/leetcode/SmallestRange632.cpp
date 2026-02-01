#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,pair<int,int>> pr;
vector<int> SmallestRange(vector<vector<int>>&arr){
    priority_queue<pr,vector<pr>,greater<pr>>pq;
    int mx = INT_MIN;
    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0],{i,0}});
        mx=max(mx,arr[i][0]);
    }
    int mn=pq.top().first;
    int start = mn,end=mx;
    while(true){
        int row= pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();
        if(col == arr[row].size()-1) break;
        pq.push({arr[row][col+1],{row,col+1}});
        mx = max(mx,arr[row][col+1]);
        mn = pq.top().first;
        if(mx-mn <end-start){
            end=mx;
            start=mn;
        }
    }
    return {start,end};
}
int main(){
    vector<vector<int>>arr={{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    vector<int>ans=SmallestRange(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}