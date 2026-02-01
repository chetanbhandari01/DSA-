#include<iostream>
using namespace std;
int main(){
    int kilo;
    cin>>kilo;
    if(kilo==2) cout<<"no";
    else if(kilo%2==0){
        cout<<"yes";
    }
    else {
        cout<<"no";
    }
    return 0;
}