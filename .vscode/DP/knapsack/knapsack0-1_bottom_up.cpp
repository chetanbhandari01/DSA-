#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int>&weight,vector<int>&profit,int w,int n){
    vector<vector<int>>arr(n+1,vector<int>(w+1));
    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            if(i==0 || j==0){
                arr[i][j]=0;
            }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(weight[i-1] <= j){
                arr[i][j] = max((profit[i-1]+arr[i-1][j-weight[i-1]]),(arr[i-1][j]));
            }
            else {
                arr[i][j] = arr[i-1][j];
            }
        }
    }
    return arr[n][w];
}
int main(){
    vector<int>weight={2,4,5,6};
    vector<int>profit={4,6,2,1};
    int n=4;
    int w = 7;
    cout<<knapsack(weight,profit,7,4);
}