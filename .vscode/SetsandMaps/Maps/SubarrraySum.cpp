#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int CountSubarray(vector<int>&arr,int k){
    int n=arr.size();
    vector<int>pre(n,0);
    pre[0]=arr[0];
    for(int i=1;i<n;i++){
        pre[i]=arr[i]+pre[i-1];
    }
    unordered_map<int,int>mp;
    int count=0;
    for(int i=0;i<n;i++){
        if(pre[i]==k){
            count++;
        }
        int rem=pre[i]-k;
        if(mp.find(rem)!=mp.end()) count+=mp[rem];
        mp[pre[i]]++;
    }
    return count;
}
int main(){
    vector<int>v={2, 2, 5, 6, 9, 2, 11};
    cout<<CountSubarray(v,2);
}