#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dp[101][101][2];  ///
int solve(string& s,int i,int j,bool istrue){
    if(i>j) return 0;
    if(i==j){
        if(istrue==true){
            return s[i]=='T';
        }
        else{
            return s[i]=='F';
        }
    }
    if(dp[i][j][istrue]!=-1){
        return dp[i][j][istrue];
    }
    int ans=0;
    for(int k=i+1;k<=j-1;k+=2){
        int LT = solve(s,i,k-1,true);
        int LF = solve(s,i,k-1,false);
        int RT = solve(s,k+1,j,true);
        int RF = solve(s,k+1,j,false);

        if(s[k]=='&'){
            if(istrue==true){
                ans =ans+(LT*RT);
            }
            else{
                ans = ans+(LF*RF)+(LF*RT)+(LT*RF);
            }
        }
        else if(s[k]=='|'){
            if(istrue==true){
                ans = ans+(LT*RT)+(LF*RT)+(LT*RF);
            }
            else{
                ans =ans+(LF*RF);
            }
        }
        else if(s[k]=='^'){
            if(istrue==true){
                ans = ans+(LF*RT)+(LT*RF);
            }
            else{
                ans =ans+(LF*RF)+(LT*RT);
            }
        }
    }
    return dp[i][j][istrue] = ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    string s="T^F&T";
    int n=s.size();
    cout<<solve(s,0,n-1,true);
}