#include<iostream>
#include<limits>
using namespace std;
int main(){
    int arr[3][3];
    cout<<"enter matrix : ";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    //max
    int max=INT_MIN;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]>max){
                max=arr[i][j];
            }
        }
    }
    //second largest
    int second=INT_MIN;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]!=max && arr[i][j]>second){
                second=arr[i][j];
            }
        }
    }
    cout<<second;
}