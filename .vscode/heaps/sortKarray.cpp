#include<iostream>
#include<queue>
using namespace std;
int main(){
    vector<int>arr={6,5,3,2,8,10,9};
    int k=3;
    priority_queue<int ,vector<int>,greater<int>>pq;
    vector<int>ans;
    for(int i=0;i<arr.size();i++){
        pq.push(arr[i]);
        if(pq.size() > k) {
            int val=pq.top();
            pq.pop();
            ans.push_back(val);
        }
    }
    while(pq.size()>0){
        ans.push_back(pq.top());
        pq.pop();
    }
    
    //printing 
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}