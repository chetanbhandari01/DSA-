#include<iostream>
#include<vector>
using namespace std;
//recursion + memoization
int mincost(vector<int>&cost,int i,vector<int>&dp){
    if(i==0 || i==1) return cost[i];
    if(dp[i]!=-1) return dp[i];
    return dp[i]=cost[i]+min(mincost(cost,i-1,dp),mincost(cost,i-2,dp));
}
// int main(){
//     vector<int>cost={1,100,1,1,1,100,1,1,100,1};
//     int n= cost.size();
//     vector<int>dp(n,-1);
//     cout<<min(mincost(cost,n-1,dp),mincost(cost,n-2,dp));
// }

//tabulation
int helper(vector<int>&cost){
    int n = cost.size();
    for(int i=2;i<cost.size();i++){
        cost[i]+=min(cost[i-1],cost[i-2]);
    }
    return min(cost[n-1],cost[n-2]);
}
int main(){
    vector<int>cost={1,100,1,1,1,100,1,1,100,1};
    cout<<helper(cost);
}