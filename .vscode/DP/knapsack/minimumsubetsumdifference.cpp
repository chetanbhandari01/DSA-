//minimum subset sum difference 
//similar to equal sum  and subset sum problem
//important problem and memoization not work for these problem
#include<iostream>
#include<vector>
using namespace std;
int minisubset(vector<int>&arr,int sum,int n){
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
    for(int i=0;i<sum+1;i++){
        dp[0][i] = false;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0] = true;
    }
    //i=n and j=sum
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(j>=arr[i-1]){
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int>v;
    for(int i=0;i<=sum/2;i++){
        if(dp[n][i]){
            v.push_back(i);
        }
    }
    int mn=INT_MAX;
    for(int i=0;i<v.size();i++){
        mn = min(mn,sum-2*v[i]);
    }
    return mn;
}
int main(){
    vector<int>profit={5,5,1,10};
    int n=4;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=profit[i];
    }
    cout<<minisubset(profit,sum,n);
}