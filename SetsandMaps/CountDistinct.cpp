#include<iostream>
#include<vector>
#include<unordered_set>
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
int countdistinct(vector<int>&nums){
    int n=nums.size();
    unordered_set<int>s;
    for(int i=0;i<n;i++){
        s.insert(nums[i]);
        int rev=reverse(nums[i]);
        s.insert(rev);
    }
    return s.size();
}
int main(){
    vector<int>s={21,9,4,53,90};
    cout<<countdistinct(s);
}