#include<iostream>
#include<vector>
using namespace std;
int LCS(string str1,string str2,int n,int m,vector<vector<int>>&dp){
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(str1[n-1] == str2[m-1]){
        return dp[n][m]= 1+LCS(str1,str2,n-1,m-1,dp);
    }
    else{
        return dp[n][m]=max(LCS(str1,str2,n,m-1,dp),LCS(str1,str2,n-1,m,dp));
    }
}
int main(){
    string str1="aefawfawfawfaw";
    string str2="aefawfeawfwafwaef";
    int n=str1.size();
    int m=str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<LCS(str1,str2,n,m,dp);
}