#include<iostream>
using namespace std;
int main(){
    int arr[4][4]={{1,2,3,4},{5,6,7,8},{9,1,2,3},{4,5,6,3}};
    for(int i=0;i<4;i++){
        if(i%2==0){
            for(int j=0;j<4;j++){
                cout<<arr[i][j];
            }
        }
        else{
            for(int k=3;k>=0;k--){
                cout<<arr[i][k];
            }
        }
    }
}
