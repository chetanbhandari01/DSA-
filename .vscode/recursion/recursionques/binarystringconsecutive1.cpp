#include<iostream>
#include<string>
using namespace std;
//generate all binary string of lenght  n without consecutive 1`s
void binary(string str,int n){
    if(n==0){
        cout<<str<<endl;
        return;
    }
    binary(str+'0',n-1);
    if(str==""){
        binary(str+'1',n-1);
    }
    else if(str[str.size()-1]=='0') {
        binary(str+'1',n-1);
    }
   
}
int main(){
    int n=3;
    binary("",n);
}