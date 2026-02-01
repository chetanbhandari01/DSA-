#include<iostream>
using namespace std;
void findunique(int arr[],int n){
    int result=0;
    for(int i=0;i<n;i++){
        result=result^arr[i];
    }
    int temp=result;
    int k=0;
    while(true){
        if((temp & 1)==1){
            break;
        }
        temp=temp>>1;
        k++;
    }
    int retval=0;
    for(int i=0;i<n;i++){
        int num=arr[i];
        if(((num >> k) & 1)==1) retval^=num;
    }
    cout<<retval<<" ";
    result=retval ^ result;
    cout<<result <<" ";
}
int main(){
    int arr[]={1,2,2,1,3,4};
    int n=6;
    findunique(arr,n);
}