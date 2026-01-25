//add two  matrix
//in addition of matrix both matrix row and column should same
#include<iostream>
using namespace std;
int main(){
    //first matrix
    int m;
    cout<<"enter row : ";
    cin>>m;
    int n;
    cout<<"enter column : ";
    cin>>n;
    //input first matrix
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int brr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>brr[i][j];
        }
    }
    //addition
    int add[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            add[i][j]=arr[i][j]+brr[i][j];
        }
    }
    //print
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<add[i][j]<<" ";
        }
        cout<<endl;
    }

    
}