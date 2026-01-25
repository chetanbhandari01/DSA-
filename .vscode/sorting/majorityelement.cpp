#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int majority(vector<int>&arr){
    int n=arr.size();
    // //not optimize 
    // for(int i=0;i<n;i++){
    //     int count=1;
    //     for(int j=i+1;j<n;j++){
    //         if(arr[i]==arr[j]){
    //             count++;
    //         }
    //     }
    //     if(count>n/2) return arr[i];
    // }
    // return -1;

    //optimize way
    sort(arr.begin(),arr.end());
    return arr[(n/2)];
}
int main(){
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    cout<<majority(arr);

}