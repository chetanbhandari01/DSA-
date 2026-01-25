#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    //sum of suffix
    for(int i=n-2;i>=0;i--){
        arr[i]=arr[i]+arr[i+1];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


    cout<<endl;

    //product of suffix
    int brr[]={1,2,3,4};
    int m=sizeof(arr)/sizeof(arr[0]);
    for(int i=n-2;i>=0;i--){
        brr[i]=brr[i]*brr[i+1];
    }
   
    for(int i=0;i<n;i++){
        cout<<brr[i]<<" ";
    }

}