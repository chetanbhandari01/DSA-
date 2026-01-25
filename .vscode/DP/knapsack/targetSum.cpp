#include<iostream>
#include<vector>
using namespace std;
//same as number of subset differences 
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
    vector<int>arr={1,1,2,3};
    int n=4;
    //formula by these two equation
    // s1 - s2 = sum
    // s1 + s2 = total
    // ---------------------
    // 2s1 = diff + total
    int total=0;
    int sum = 1; //given
    for(int i=0;i<n;i++){
        total+=arr[i];
    }
    //so s1 is sum+diff/2
    int s1 = (total+sum)/2;
    vector<vector<int>>dp(n+1,vector<int>(s1+1,-1));
    cout<<subsetcount(arr,n,s1,dp);

}