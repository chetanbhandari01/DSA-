#include<iostream>
using namespace std;
int main(){
    int n;  // no of problems
    cin>>n;
    int count=0;
    int a,b,c;
    for(int i=0;i<n;i++){
        cin>>a;
        cin>>b;
        cin>>c;
        if(a+b+c>=2) {
            count++;
        }
    }
    cout<<count;

}