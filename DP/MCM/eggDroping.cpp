#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int dp[101][101];
int solve(int e,int f){
    if(e==1){
        return f;
    }
    if(f==1 || f==0){
        return f;
    }
    if(dp[e][f]!=-1){
        return dp[e][f];
    }
    int mn=INT_MAX;
    for(int k=1;k<=f;k++){
        int Break;
        int nbreak;
        if(dp[e-1][k-1]!=-1){
            Break=dp[e-1][k-1];
        }
        else{
            Break=solve(e-1,k-1);
            dp[e-1][k-1]=Break;
        }
        if(dp[e][f-k]!=-1){
            nbreak= dp[e][f-k];
        }
        else{
            nbreak=solve(e,f-k);
            dp[e][f-k]=nbreak;
        }
        int temp= 1+ max(Break,nbreak);
        mn=min(mn,temp);
    }
    return dp[e][f]=mn;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int e,f;
    cout<<solve(2,6);
}