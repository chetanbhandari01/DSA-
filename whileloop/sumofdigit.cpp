//sum of digit 
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number : ";
    cin>>n;
    int sum=0;
    int temp=n;
    while(n>0){
        temp=n%10;  //lastdigit
        sum+=temp;   
        n=n/10;
    }
    cout<<sum;
}