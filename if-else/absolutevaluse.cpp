//given an integer print the absolute value of that integer
#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"enter number : ";
    cin>>x;
    if(x>=0){
        cout<<x;
    }
    if(x<0){
        cout<<(x*(-1));
    }
}