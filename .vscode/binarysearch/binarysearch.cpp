#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int search (vector<int>&arr ,int target){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int lower=0;
    int high=n-1;
    while(lower<=high){
        int mid =(lower+high)/2;
        if(arr[mid]==target) return mid;
        if(arr[mid]<target) lower=mid+1;
        if(arr[mid]>target) high=mid-1;
    }
    return -1;
}
int main(){
    vector<int>arr;
    arr.push_back(3);
    arr.push_back(9);
    arr.push_back(8);
    arr.push_back(7);
    arr.push_back(32);
    arr.push_back(34);
    arr.push_back(1);
    cout<<search(arr,7);
    
}