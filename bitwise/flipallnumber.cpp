#include<iostream>
using namespace std;
int flip(int n){
    int temp=n;
    n=n | (n >> 1);
    n=n | (n >> 2);
    n=n | (n >> 4);
    n=n | (n >> 8);
    n=n | (n >> 16);
    int result=temp^n;
    return (result);
}
int main(){
    cout<<flip(5);
}