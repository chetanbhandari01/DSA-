#include<iostream>
#include<vector>
using namespace std;
int require(vector<int>&coin,int n,int sum,vector<vector<int>>dp){
    if(sum==0) return 0;
    if(n==0) return INT_MAX-1;
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(coin[n-1] <=sum){
        return dp[n][sum]= min(1+require(coin,n,sum-coin[n-1],dp),require(coin,n-1,sum,dp));
    }
    else{
        return dp[n][sum]=require(coin,n-1,sum,dp);
    }
}
int main(){
    vector<int>coin={1,2,3};
    int rupee = 5;
    int n=3;
    vector<vector<int>>dp(n+1,vector<int>(rupee+1,-1));
    cout<<require(coin,n,rupee,dp);
}