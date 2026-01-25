// reverse triangle 
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
    int x=n;
    for(int i=1;i<=n;i++){
        for(int k=i-1;k>=1;k--){
            cout<<" ";
        }
        for(int j=2*x-1;j>=1;j--){
            cout<<"*";
            
        }
        x--;
        cout<<endl;
    }
}

