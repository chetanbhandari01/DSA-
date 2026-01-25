#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&arr,int i,int j,vector<vector<int>>&dp){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mn=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int tempans = solve(arr,i,k,dp)+solve(arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j];
        mn=min(mn,tempans);
    }
    return dp[i][j]=mn;
}
int main(){
    vector<int>arr={40,20,30,10,40};
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    cout<<solve(arr,1,n-1,dp);
}