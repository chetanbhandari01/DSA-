#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter number : ";
    cin>>n;
    for(int i=0;i<=n;i++){         //nCr=factorial of n divived by r factorial * n-r factorial 
        int current=1;           //nCr+1=nCr * n-r/r+1
        for(int j=0;j<=i;j++){        //nCr+1 =currnt *i+j/j+1 is there by mathimatically
            cout<<current<<" ";
            current=current*(i-j)/(j+1);
        }
        cout<<endl;
    }
}