//count digits of a given number
#include<iostream>
using namespace std;
int main(){
    int n=1;
    int count =0;
    int temp=n;
    while(temp>0){
        temp=temp/10;
        count++;
    }
    
    if(n==0){
        cout<<1;
    }
    else{
        cout<<count;
    }
}