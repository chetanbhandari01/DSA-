#include<iostream>
using namespace std;
int main(){
    int m;
    cout<<"enter a row : ";
    cin>>m;
    int n;
    cout<<"enter a column : ";
    cin>>n;

    //first matrix
    int arr[m][n];
    cout<<"enter matrix : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    //second matrix
    int p;
    cout<<"enter a row : ";
    cin>>p;
    int q;
    cout<<"enter a column : ";
    cin>>q;

    int arr1[p][q];
    cout<<"enter matrix : "<<endl;
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cin>>arr1[i][j];
        }
    }
    //check
    int result[m][q];
    if(n!=p){
        cout<<"invlaid matrix ";
    }
    else{
        for(int i=0;i<m;i++){
            for(int j=0;j<q;j++){
                result[i][j]=0;
                //result[i][j]=a[i][0]*b[0][j] +a[i][1]*b[1][j]+
                for(int k=0;k<n;k++){
                    result[i][j]+=arr[i][k]*arr1[k][j];
                }
            }
        }
    }
    //print
    cout<<"resultant matrix : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}