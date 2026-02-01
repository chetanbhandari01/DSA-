#include<iostream>
using namespace std;
int gcd(int a,int b){
    for(int i=min(a,b);i>=2;i--){
        if(a%i==0 && b%i==0) return i;
    }
    return 1;
}
int gcd_recursive(int a,int b){
    if(a==0) return b;
    else return gcd_recursive(b%a,a);
}
int main(){
    int a=2;
    int b=3;
    cout<<gcd(a,b)<<endl;
    cout<<gcd_recursive(a,b);
}   