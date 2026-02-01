#include<iostream>  //867 leetcode
using namespace std;
int main(){
    int m;
    cout<<"enter size : ";
    cin>>m;
    int arr[m][m];
    cout<<"enter matrix : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    //transpose
    int trans[3][3];
    for(int i=0;i<m;i++){
        for(int j=0;j<=i;j++){
            int temp=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=temp;
            
        }
    }
    //print
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}