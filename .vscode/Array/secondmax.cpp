#include<iostream>
#include<limits>
using namespace std;
int main(){
    int arr[7]={1,2,3,5,6,4,3};
    int max=INT_MIN;
    for(int i=0;i<=6;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int secondmax=INT_MIN;
    for(int i=0;i<=6;i++){
        if(arr[i]!=max && arr[i]>secondmax){
            secondmax=arr[i];
        }
    }

    cout<<max<<endl;
    cout<<secondmax<<endl;
}