#include<iostream>
using namespace std;
//maximum number in array
int maxarray(int arr[],int n,int idx ){
    if(idx==n)return INT_MIN;
    return max(arr[idx],maxarray(arr,n,idx+1));
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<maxarray(arr,n,0);
}




