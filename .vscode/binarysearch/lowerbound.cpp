#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1,,23,4,5,18,20,21
//lower bound means target is 20 than print lower bound is 18
    int search (vector<int>&arr ,int target){
    sort(arr.begin(),arr.end());
    int n=arr.size();
    int lower=0;
    int high=n-1;
    bool flag =false;
    while(lower<=high){
        int mid =lower + (high-lower)/2;
        if(arr[mid]==target) {
            flag =true;
            return arr[mid-1];
            break;
        }
        if(arr[mid]<target) lower=mid+1;
        if(arr[mid]>target) high=mid-1;
        
    }
    return arr[high];    //mean loop end hogaya (high is greater than lower)
}
int main(){
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(9);
    arr.push_back(15);
    arr.push_back(18);
    cout<<search(arr,6);
    
}
