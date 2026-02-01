#include<iostream>
#include<vector>
using namespace std;
int require(vector<int>&coin,int n,int rupee,vector<vector<int>>&dp){
    if(rupee==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][rupee]!=-1) return dp[n][rupee];
    if(rupee>=coin[n-1]){
        return dp[n][rupee] = require(coin,n,rupee-coin[n-1],dp) + require(coin,n-1,rupee,dp);
    }
    else{
        return dp[n][rupee] = require(coin,n-1,rupee,dp);
    }
}
int main(){
    vector<int>coin={1,2,3};
    int rupee = 5;
    int n=3;
    vector<vector<int>>dp(n+1,vector<int>(rupee+1,-1));
    cout<<require(coin,n,rupee,dp);
}
