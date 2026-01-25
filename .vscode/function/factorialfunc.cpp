#include<iostream>
using namespace std;
int factorial(int x){
    int fact=1;
    for(int i=1;i<=x;i++){
        fact*=i;
        cout<<fact<<endl;
    }
    return fact;
}
int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
    factorial(n);
}