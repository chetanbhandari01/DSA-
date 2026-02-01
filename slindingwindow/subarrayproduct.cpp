//subarray product less than k
//leetcode 713
#include<iostream>
#include<vector>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k<=1) return 0;
    int n=nums.size();
    int i=0;
    int j=0;
    int count=0;
    int product=1;
    while(j<n){
        product *=nums[j];
        while(product>=k){
            count +=(j-i);
            product /=nums[i];
            i++;
        }
        j++;
    }
    while(i<n){
        count +=(j-i);
        product /=nums[i];
        i++;
    }
    return count;
}
int main(){
    vector<int >v={10,5,2,3};
    int k=100;
    cout<<numSubarrayProductLessThanK(v,k);
}