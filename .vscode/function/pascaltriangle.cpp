#include<iostream>
using namespace std;
int fact(int n){
    int facto=1;
    for(int i=1;i<=n;i++){
        facto*=i;
    }
    return facto;
}
int combination(int n,int r){
    int combi=fact(n)/(fact(r)*fact(n-r));
    return combi;
}
int main(){
    int n;  //no.of row
    int r;   //no.of column
    cout<<"enter n : ";
    cin>>n;
    cout<<"enter r : ";
    cin>>r;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<combination(i,j)<<" ";
        }
        cout<<endl;
    }
}