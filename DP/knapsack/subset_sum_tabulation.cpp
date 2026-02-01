#include<iostream>
#include<vector>
using namespace std;
int subset(vector<int>&arr,int sum,int n){
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1));
    for(int i=0;i<sum+1;i++){
        dp[0][i]= false;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=true;
    }
    //i=n and j=sum
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(j>=arr[i-1]){
                dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    vector<int>val={2,3,7,8,10};
    int sum = 11;
    int n=5;
    cout<<subset(val,sum,n);

}
