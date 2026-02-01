#include<iostream>
#include<vector>
using namespace std;
bool equalsum(vector<int>&arr,int n,int sum){
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
    for(int i=0;i<sum+1;i++){
        dp[0][i]= false;
    }
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    //i=n and j=sum
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(j>=arr[i-1]){
                dp[i][j] = dp[i-1][sum-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
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
        cout<<equalsum(arr,n,sum/2);
    }
    
}