#include<iostream>
#include<vector>
using namespace std;
int main(){ 
    int arr[]={5,2,0,2,1,7,6,0,0};
    int n=9;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]==0){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


