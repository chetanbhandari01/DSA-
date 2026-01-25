#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str="chetan";
    //str.substr(index,len)
    cout<<str.substr(2)<<endl;     //index ke aage ka sab lo
    cout<<str.substr(2,3);  //(2,3)  =e se 3 lenght tak
}