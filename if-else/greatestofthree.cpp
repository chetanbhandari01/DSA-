#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"enter 1st number : ";
    cin>>x;
    int y;
    cout<<"enter 2nd number : ";
    cin>>y;
    int z;
    cout<<"enter 3rd number : ";
    cin>>z;
    if(x>y && x>z){
        cout<<"x is greater";
    }
    else if(y>z){
        cout<<"y is greater";
    }
    else{
        cout<<"z is greater";
    }

}