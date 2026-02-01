#include<iostream>
#include<vector>
using namespace std;
bool equalsum(vector<int>&arr,int n,int sum,vector<vector<int>>dp){
    if(sum==0) return true;
    if(n==0) return false;
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(sum>=arr[n-1]){
        return dp[n][sum] = equalsum(arr,n-1,sum-arr[n-1],dp) || equalsum(arr,n-1,sum,dp);
    }
    else {
        return dp[n][sum]= equalsum(arr,n-1,sum,dp);
    }
}

int main(){
    vector<int>arr={8,8,8,2};
    int n=4;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0) cout<<0;
    else {
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        cout<<equalsum(arr,n,sum/2,dp);
    }
    
}