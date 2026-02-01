#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int LCS(string& str1,string& str2,int n,int m){
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<m+1;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    //i,j
    int i=n,j=m;
    string result="";
    while(i>0 && j>0){
        if(str1[i-1]==str2[j-1]){
            result.push_back(str1[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }  
            else{  //dp[i][j-1]>dp[i-1][j] 
                j--;
            }
        }
    }
    reverse(result.begin(),result.end());
    cout<<result;
    return 0;
}
int main(){
    string str1="geeksforgeeks";
    string str2="eksrg";
    int n=str1.size();
    int m=str2.size();
    LCS(str1,str2,n,m);
}
