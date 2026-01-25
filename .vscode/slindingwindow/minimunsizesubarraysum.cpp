// leetcode 209
#include<iostream>
#include<vector>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
    int n=nums.size();
    int i=0;
    int j=0;
    int minlen=INT_MAX;
    int len;
    int sum=0;
    while(j<n){
        sum +=nums[j];
        while(sum>=target){
            len=j-i+1;  //index
            minlen=min(minlen,len);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    if(minlen==INT_MAX) return 0;
    else return minlen;
}
int main(){
    vector<int>v={2,3,1,2,4,3};
    int target=7;
    cout<<minSubArrayLen(target,v);
}
