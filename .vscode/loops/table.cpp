#include<iostream>
using namespace std;
int main(){
    // int n;
    // cout<<"enter a number : ";
    // cin>>n;
    // for(int i=1;i<=10;i++){
    //     cout<<n <<"*" <<i <<"="<<n*i<<endl;
    // }

    //AP 4,7,10,13,16,19
    int n=10;
    int a=4;
    for(int i=1;i<=3*n-1;i++){
        cout<<a<<endl;
        a+=3;
    }
}