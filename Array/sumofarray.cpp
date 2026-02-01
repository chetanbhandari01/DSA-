#include<iostream>
using namespace std;
int main(){
    int arr[7]={1,2,3,5,6,4,3};
    int sum=0;
    for(int i=0;i<=6;i++){
        sum+=arr[i];
    }
    cout<<sum;
}