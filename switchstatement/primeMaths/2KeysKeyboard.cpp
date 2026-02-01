#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int n){  //for use better time complexity
    if(n==1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
} 
int gd(int n){  //higest factor 
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return n/i;  //n/i means higest factor
    }
    return 1;
}
int minSteps(int n) {
    int count=0;
    while(n>1){
        if(isprime(n)){   //if n=5 and its prime than n operation needed
            count+=n;
            break;
        }
        int hf=gd(n);
        count += (n/hf);
        n=hf;
    }
    return count;
}
int main(){
    cout<<minSteps(20);
}