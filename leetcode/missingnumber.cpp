//268
//better solution is mathematically only this is using cyclic sort method
#include<iostream>
#include<vector>
using namespace std;
int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int correctidx=nums[i];
            if(correctidx==i || nums[i]==n) i++;
            else swap(nums[i],nums[correctidx]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i) return i;
        }
        return n;
}
int main(){
    vector<int> nums={1,5,3,2,0};
    cout<<missingNumber(nums);
}
