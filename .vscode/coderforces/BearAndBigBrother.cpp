#include<iostream>
using namespace std;
int main(){
    int a;
    int b;
    cin>>a;//increased by 3
    cin>>b;  //increased by 2
    int count=0;
    while(b>=a){
        a*=3;
        b*=2;
        count++;
    }
    cout<<count;
}