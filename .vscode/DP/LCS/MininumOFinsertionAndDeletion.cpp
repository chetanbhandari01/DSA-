#include<iostream>
#include<vector>
using namespace std;
// minimum of insertion and deletion from a-> b  solve by lCS logic only
int LCS(string& str1,string& str2,int n,int m){
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<m+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string str1="heap";
    string str2="pea";
    int n=str1.size();
    int m=str2.size();
    //a--->b
    int deletion = n-LCS(str1,str2,n,m);  //n-lcs=ea ->2
    int insertion = m-LCS(str1,str2,n,m);  // m-lcs = 3-2 -> 1
    cout<<deletion<<" "<<insertion;
}