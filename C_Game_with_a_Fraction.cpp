#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long p ,q;
        cin>>p>>q;
        
        long long d = q-p;
        if(q>p && p >= 2*d && q>=3*d ){
            cout<<"Bob"<<endl;
        }
        else cout<<"Alice"<<endl;
    }
}