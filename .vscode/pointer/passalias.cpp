#include<iostream>
using namespace std;
void swap(int &a,int &b){
    //using variable
    int temp=a;
    a=b;
    b=temp;
}
int main(){
    int a;
    int b;
    cout<<"enter number : ";
    cin>>a;
    cout<<"enter number : ";
    cin>>b;
    swap(a,b);
    cout<<a<<" "<<b;
}