//count subset of given sum
#include<iostream>
#include<vector>
using namespace std;
int subsetcount(vector<int>&arr,int n,int sum){
    vector<vector<int>>dp(n+1,vector<int>(sum+1));
    for(int i=0;i<sum+1;i++){
        dp[0][i] = 0;
    }
    dp[0][0] =1;  //for {0,0,1} condition
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(j>=arr[i-1]){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    vector<int>arr={5,3,10,2,10};
    int n=5;
    int sum = 10;
    cout<<subsetcount(arr,n,sum);
}
