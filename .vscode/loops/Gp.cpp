#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number : ";
    cin>>n;
    // gp=1,2,4,8,16....
    int a=1;
    for(int i=1;i<=n;i++){
        cout<<a<<endl;
        a=a*2;
    }

}