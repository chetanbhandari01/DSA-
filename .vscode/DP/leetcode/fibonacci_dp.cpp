#include<iostream>
#include<vector>
using namespace std; 
//recursion + memoization
int fibo(int n,vector<int>&dp){
    if(n==0 || n==1) return n;
    if(dp[n]!=-1) return dp[n];
    dp[n]= fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}
// int main(){
//     int n=9;
//     vector<int>dp(n+1,-1);
//     cout<<fibo(n,dp);
// }

// iterative / tabulation
int fibo(int n){
    vector<int>dp(n+1);
    if(n==0 ||n==1) return n;
    dp[0]=0 ,dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n=9;
    cout<<fibo(n);
}