#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool ispalindrome(string& s,int i,int j){
    string str="";
    for(int k=i;k<=j;k++){
        str+=s[k];
    }
    string rev=str;
    reverse(rev.begin(),rev.end());
    return str==rev;
}

int solve(string& s,int i,int j,vector<vector<int>>&dp){
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(ispalindrome(s,i,j)==true) return 0;
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int left;
        int right;
        if(dp[i][k]!=-1){
            left=dp[i][k];
        }
        else{
            left=solve(s,i,k,dp);
            dp[i][k]=left;
        }
        if(dp[k+1][j]!=-1){
            right=dp[k+1][j];
        }
        else {
            right = solve(s,k+1,j,dp);
            dp[k+1][j]=right;
        }
        int temp=1+left+right;
        ans=min(temp,ans);
    }
    return dp[i][j]=ans;
}
int main(){
    string str = "abcb";
    int n=str.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    cout<<solve(str,0,n-1,dp);
}