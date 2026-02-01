//maximum sum of subarray of size K
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={9,9,1,5,8,4,9,3,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int prevsum=0;
    int maxsum=INT_MIN;
    for(int i=0;i<k;i++){
        prevsum+=arr[i];
    }
    maxsum=prevsum;
    //slinding window
    int i=1;
    int j=k;
    while(j<n){
        int currentsum=prevsum+arr[j]-arr[i-1];
        if(maxsum<currentsum){
            maxsum=currentsum;
        }
        prevsum=currentsum;
        i++;
        j++;
    }
    cout<<maxsum;

}


// Brute force

// int main(){
//     //brute force 
//     int arr[]={1,2,3,4,5,6,7,9,8};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int k=3;
//     int ans[6];
//     int maxsum=INT_MIN;
//     for(int i=0;i<=n-k;i++){
//         int sum=0;
//         for(int j=i;j<k+i;j++){
//             sum+=arr[j];
//         }
//         maxsum=max(maxsum,sum);
//     }
//     cout<<maxsum;
// }