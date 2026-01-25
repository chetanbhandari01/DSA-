#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int reverse(int n){
    int temp=n;
    int rev=0;
    while(n>0){
        temp=n%10;
        rev=rev*10+temp;
        n/=10;
    }
    return rev;
}
int countNicePair(vector<int>&nums){
    unordered_map<int,int>m;
    int count=0;
    for(auto x:nums){
        int sum=x-reverse(x);
        if(m.find(sum)!=m.end())count+=m[sum];
        m[sum]++;
    }
    return count;
}
int main(){
    vector<int>arr={13,10,35,24,76};
    cout<<countNicePair(arr);
}