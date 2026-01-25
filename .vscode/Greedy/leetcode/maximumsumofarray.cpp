#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int largestSumAfterKNegations(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
    }
    while(k>0){
        int mini=pq.top();
        pq.pop();
        mini=-mini;
        pq.push(mini);
        k--;
    }
    int sum=0;
    while(pq.size()>0){
        sum+=pq.top();
        pq.pop();
    }
    return sum;
}
int main(){
    vector<int> nums={4,2,3};
    int k=1;
    cout<<largestSumAfterKNegations(nums,k);
}
