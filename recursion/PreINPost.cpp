//pre IN post most important
#include<iostream>
using namespace std;
void zigzag(int n){
    if(n==0) return;
    cout<<n;  //PRE
    zigzag(n-1);
    cout<<n;   //IN
    zigzag(n-1);
    cout<<n;  //POST
}
//211121112   like call stack 
int main(){
    zigzag(2);
}