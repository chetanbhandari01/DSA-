//greastest common diviser means higest value that divisible by both
// (24,60) =so,hcf is means min(24,60) is 24 so from 24 to 1 loop is start and check which number is divisible to both number
#include<iostream>
using namespace std;
int gcd(int a,int b){
    int hcf=1;
    for(int i=min(a,b);i>=1;i--){      //for optimized way
        if(a%i==0 && b%i==0){
            hcf=i;
            break;
        }
    }
    return hcf;
}
int main(){
    int a;
    int b;
    cout<<"enter a number : ";
    cin>>a;
    cout<<"enter a number : ";
    cin>>b;
    cout<<gcd(a,b);
}