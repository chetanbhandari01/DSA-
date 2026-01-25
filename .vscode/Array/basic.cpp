#include<iostream>
using namespace std;
int main(){
    int arr[7]={1,2,3,5,6,4,3};
    arr[6]=4;   //changing value
    cout<<arr[5]<<endl;
    for(int i=0;i<=6;i++){
        cout<<arr[i]<<" ";
    }
}