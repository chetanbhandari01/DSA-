//count subset of given sum
#include<iostream>
#include<vector>
using namespace std;
int subsetcount(vector<int>&arr,int n,int sum,vector<vector<int>>&dp){
    if(sum==0){
        return 1;
    }
    if(n==0) return 0;
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(sum>=arr[n-1]){
        return dp[n][sum]= subsetcount(arr,n-1,sum-arr[n-1],dp) + subsetcount(arr,n-1,sum,dp);
    }
    else {
        return dp[n][sum]= subsetcount(arr,n-1,sum,dp);
    }
}
int main(){
    vector<int>arr={5,3,10,2,10};
    int n=5;
    int sum = 10;
    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
    cout<<subsetcount(arr,n,sum,dp);
}