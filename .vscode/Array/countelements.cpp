#include<iostream>
using namespace std;
int main(){
    int arr[6]={1,3,5,6,7,8};
    int x=3;
    int count=0;
    for(int i=0;i<6;i++){
        if(arr[i]>x){
            count++;
        }
    }
    cout<<count;
}