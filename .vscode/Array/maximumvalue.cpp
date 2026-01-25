#include<iostream>
#include<limits>
using namespace std;
int main(){
    int arr[7]={3,2,3,5,60,4,300};
    int max=INT_MIN;   //arr[0] we can use INT_MIN
    for(int i=0;i<=6;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    cout<<max;
}