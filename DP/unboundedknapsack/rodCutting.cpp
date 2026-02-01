#include<iostream>
#include<vector>
using namespace std;
int rodmax(vector<int>&length,vector<int>&prices,int n,int l,vector<vector<int>>&dp){
    if(n==0 || l==0) return 0;
    if(dp[n][l] != -1) return dp[n][l];
    if(length[n-1] <=l){
        return dp[n][l] = max(prices[n-1]+rodmax(length,prices,n,l-length[n-1],dp),rodmax(length,prices,n-1,l,dp));
    }
    else{
        return dp[n][l] = rodmax(length,prices,n-1,l,dp);
    }
}
int main(){
    vector<int>length={1,2,3,4,5,6,7,8};
    vector<int>prices={1,5,8,9,10,17,17,20};
    int n=8;
    int l=8;
    vector<vector<int>>dp(n+1,vector<int>(l+1,-1));
    cout<<rodmax(length,prices,n,l,dp);
}