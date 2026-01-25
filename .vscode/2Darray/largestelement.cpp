#include<iostream>
#include<limits>
using namespace std;
int main(){
    //find largest element of a given 2d array
    int arr[3][3];
    cout<<"enter matrix : ";
    int max=INT_MIN;
    //input
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i][j]>max){
                max =arr[i][j];
            }
        }
    }
    cout<<max;
}