#include<iostream>
#include<vector>
using namespace std;
bool subset(vector<int>&arr,int sum,int n,vector<vector<int>>&dp){
    if(sum==0) return true;
    if(n==0){
        return false;
    }
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(sum>= arr[n-1]){
        return dp[n][sum]= subset(arr,sum-arr[n-1],n-1,dp) || subset(arr,sum,n-1,dp);
    }
    else{
        return dp[n][sum]=subset(arr,sum,n-1,dp);
    }
}
int main(){
    vector<int>val={2,3,7,8,10};
    int sum = 11;
    int n=5;
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    cout<<subset(val,sum,n,dp);
}
