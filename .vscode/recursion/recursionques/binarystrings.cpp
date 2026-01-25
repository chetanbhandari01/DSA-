#include<iostream>
#include<string>
using namespace std;
//generate all binary string of lenght  n 
void binary(string str,int n){
    if(str.length()==n){
        cout<<str<<endl;
        return;
    }
    binary(str+'0',n);
    binary(str+'1',n);
}
int main(){
    int n=3;
    binary("",n);
}