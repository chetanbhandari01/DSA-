//fibonacci number
#include<iostream>
using namespace std;
int main(){
    int n=5;
    int a=1;//prev2  n==1
    int b=2;  //prev1  n==2
    int sum=0;
    if(n==1) return 1;
    if(n==2) return 1;
    for(int i=3;i<=n;i++){
        sum=a+b;
        a=b;
        b=sum;
    }
    cout<<sum;
}