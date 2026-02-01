//first negative number in every window of size k
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={2,-3,4,4,-7,-1,4,-2,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=3;
    int prevIdx=-1;    //index
    int ans[7];   //7 cha jaghi n-k+1 kar
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            prevIdx=i;
            break;
        }
    }
    if(prevIdx==-1) ans[0]=1;  //in kTH no negative number than store 1
    else ans[0]=arr[prevIdx];

    //slding window
    int i=1;
    int j=k;
    while(j<n){
        if(prevIdx>=i) ans[i]=arr[prevIdx];
        else {
            prevIdx=-1;
            for(int x=i;x<=j;x++){
                if(arr[x]<0){
                    prevIdx=x;
                    break;
                }
            }
            if(prevIdx!=-1) ans[i]=arr[prevIdx];
            else ans[i]=1;  //p= -1
        }
        i++;
        j++;
    }
    for(int i=0;i<n-k+1;i++){
        cout<<ans[i]<<" ";
    }
}




//brute force

// int main(){
//     int arr[]={2,-3,4,4,-5,1,-4,-2,6};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int k=3;
//     int ans[7];
//     for(int i=0;i<n-k+1;i++){
//         for(int j=i;j<i+k;j++){
//             if(arr[j]<0) {
//                 ans[i]=arr[j];
//                 break;
//             }
//         }
//     }
//     for(int i=0;i<n-k+1;i++){
//         cout<<ans[i]<<" ";
//     }
// }