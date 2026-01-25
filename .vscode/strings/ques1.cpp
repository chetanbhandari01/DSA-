#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//input a string of even lenght and reverse the first half of the string
int main(){
    string str;
    cout<<"enter string : ";
    getline(cin,str);
    int len=str.size();
    reverse(str.begin(),str.begin()+(len/2));  //yeah pe plus one nahi kiya ki(0,0+3) for example size 6 tu
    cout<<str;
}