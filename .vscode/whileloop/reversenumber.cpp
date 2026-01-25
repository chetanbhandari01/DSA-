//write a program to print reverse of a given number 
#include<iostream>
using namespace std;
int main(){
    int n=123456789;
    int temp;
    int reverse=0;
    while(n>0){
        temp=n%10;
        reverse=reverse*10+temp;
        n=n/10;
    }
    cout<<reverse;
}