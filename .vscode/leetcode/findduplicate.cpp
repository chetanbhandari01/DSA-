//287
#include<iostream>
#include<vector>
using namespace std;
int findDuplicate(vector<int>& nums) {
    int len=nums.size();
    int i=0;
    while(i<len){
        int correctidx=nums[i];
        if(nums[correctidx]==nums[i]) return nums[i];
        else swap(nums[i],nums[correctidx]);
    }
    return 100;
}
int main(){
    vector<int>nums={3,2,2,4,5};

    cout<<findDuplicate(nums);
}