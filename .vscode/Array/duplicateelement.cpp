#include<iostream>
#include<vector>
using namespace std;
int duplicate(vector<int>&arr){
    int i=0;
    for(int j=0;j<arr.size();j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
    }
    return i+1;
}
int main(){
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    cout<<duplicate(arr);
}