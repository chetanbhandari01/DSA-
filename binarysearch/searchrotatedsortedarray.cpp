//leetcode 33 
#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int n=nums.size();
    int lo=0;
    int hi=n-1;
    if(n==2){  //array me 2 hee element hai tu
        if(target==nums[0]) return 0;
        else if(target==nums[1]) return 1;
        else return -1;
    }
    //finding pivot element
    int pivot=-1;        //smallest element
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid==0) lo=mid+1;        
        else if(mid==n-1) hi=mid-1;       
        else if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]){  //if 6,8,20,1,8,3,7 so 1 is pivot
            pivot=mid;
            break;
        }
        else if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){  //if 6,8,20,33,1,3,7 so 1 is pivot
            pivot=mid+1;
            break;
        }
        else if(nums[mid]>nums[hi]) lo = mid+1;
        else hi=mid-1;
    }
        //finding target
        if(pivot==-1){  //if array already sorted ,no rotations
            lo=0;
            hi=n-1;
            while(lo<=hi){
                
                int mid=lo+(hi-lo)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) hi=mid-1;
                else lo=mid+1;
            }
            return -1;
        }
        //ye mixed array keley hai
        if(target>=nums[0] && target <=nums[pivot-1]){
            lo=0;
            hi=pivot-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) hi=mid-1;
                else lo=mid+1;
            }
        }
        else{
            lo=pivot;
            hi=n-1;
            while(lo<=hi){
                int mid=lo+(hi-lo)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) hi=mid-1;
                else lo=mid+1;
            }
        }
        
    
    return -1;
}

int main(){
    vector<int>arr;
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    cout<<search(arr,0);
}