#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<arr.size();i++){
        int dis= abs(x-arr[i]);
        pq.push({dis,arr[i]});
        if(pq.size() >k) pq.pop();
    }
    vector<int>ans;
    while(pq.size()>0){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    vector<int>arr={1,2,3,4,5};
    vector<int>ans=findClosestElements(arr,4,3);
    for(int x:ans){
        cout<<x<<" ";
    }
}