#include<iostream>
using namespace std;
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    //transpose
    for(int i=0;i<3;i++){
        for(int j=0;j<=i;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
        }
    }
    //reverse 
    for(int i=0;i<3;i++){
        for(int j=2;j>=0;j--){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}



    