#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b,c,d;
        cin>>a;
        cin>>b;
        cin>>c;
        cin>>d;
        if(a!=b ||b!=c || c!=d){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
}