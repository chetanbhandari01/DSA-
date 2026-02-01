#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,7,9,7,6,5,5};
    int size=sizeof(arr)/sizeof(arr[0]);   //sizeof(arr)/4 means divided by size of integer
    cout<<size;
}