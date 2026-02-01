#include<iostream>
#include<vector>
using namespace std;
int peakmountain(vector<int> &arr){
    int n=arr.size();
    int lo=0;
    int hi=n-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
            return mid;
        }
        else if(arr[mid]>arr[mid+1]){
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return 0;
}
int main(){
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(2);
    cout<<peakmountain(arr);
}
