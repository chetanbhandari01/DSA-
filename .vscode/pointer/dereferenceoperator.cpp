#include<iostream>
using namespace std;
int main(){
    int x=456;
    int*p =&x;
    cout<<*p<<endl;

    // change value of x
    int a=321;
    int *ptr=&a;
    cout<<a<<endl;
    *ptr=890;
    cout<<a<<endl;
}