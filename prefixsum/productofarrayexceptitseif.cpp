//238 leetcode 
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v1={1,2,3,4};
    int n=v1.size();
    vector<int>prefix(n);
    prefix[0]=1;
    int product=v1[0];
    for(int i=1;i<n;i++){
        prefix[i]=product;
        product *=v1[i];
    }
    //suffix
    vector<int>suffix(n);
    suffix[n-1]=1;
    product=v1[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=product;
        product=product*v1[i];
    }
    //ans vector  
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        ans[i]=prefix[i]*suffix[i];
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    
}