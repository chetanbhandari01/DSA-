#include<iostream>
#include<vector>
using namespace std;
int rodmax(vector<int>&length,vector<int>&prices,int n,int l){
    vector<vector<int>>dp(n+1,vector<int>(l+1));
    for(int i=0;i<l+1;i++){
        dp[0][i]= 0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]= 0;
    }
    //i=n and j=l
    for(int i=1;i<n+1;i++){
        for(int j=1;j<l+1;j++){
            if(length[i-1] <=j){      
                dp[i][j] = max(prices[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][l];
}
int main(){
    vector<int>length={1,2,3,4,5,6,7,8};
    vector<int>prices={1,5,8,9,10,17,17,20};
    int n=8;
    int l=8;
    cout<<rodmax(length,prices,n,l);
}