#include<iostream>
using namespace std;
int main(){
    int arr[]={5,3,1,4,2};
    int n=5;
    for(int i=1;i<n;i++){
        int j=i;
        while(j>=1){
            if(arr[j]>arr[j-1]) break;
            if(arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
                
            }
            j--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}