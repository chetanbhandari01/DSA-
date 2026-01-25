#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int>&weight,vector<int>&profit,int w,int n,vector<vector<int>>&dp){
    if(n==0 || w==0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(weight[n-1]<=w){
        return dp[n][w] =  max((profit[n-1]+knapsack(weight,profit,w-weight[n-1],n-1,dp)),knapsack(weight,profit,w,n-1,dp));
    }
    else{
        return dp[n][w] = knapsack(weight,profit,w,n-1,dp);
    }
}
int main(){
    vector<int>weight={2,4,5,6};
    vector<int>profit={4,6,2,1};
    int n=4;
    int w = 7;
    vector<vector<int>>dp(n+1, vector<int>(w+1,-1));
    cout<<knapsack(weight,profit,7,4,dp);
}