#include<iostream>
using namespace std;
int main(){
    int arr[5][5];
    int a;
    int p;
    int q;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>a;
            if(a==1) {
                p=i+1;
                q=j+1;
            }
            arr[i][j]=a;
        }
    }
    int ans= abs(3-p)+abs(3-q);
    cout<<ans;

}