#include<iostream>
#include<vector>
using namespace std;
int require(vector<int>&coin,int n,int rupee){
    vector<vector<int>>dp(n+1,vector<int>(rupee+1));
    for(int i=0;i<rupee+1;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0] =1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<rupee+1;j++){
            if(j>=coin[i-1]){
                dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][rupee];
}
int main(){
    vector<int>coin={1,2,3};
    int rupee = 5;
    int n=3;
    cout<<require(coin,n,rupee);
}
