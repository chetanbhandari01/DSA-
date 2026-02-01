#include<iostream>
using namespace std;
int main(){
    int arr[2][2]={{1,2},{1,4}};
    cout<<arr[0][1]<<endl;

    //input from user
    int arr1[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr1[i][j];
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }
}