#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str="chetan bhandari";
    cout<<str.size()<<endl;  //instead of size you can use lenght also
    cout<<str.length()<<endl;

    //push back means adding character
    string str1="asdfg";
    cout<<str1<<endl;
    str1.push_back('q');  //will pushing only one character is push
    str1.push_back('u');
    cout<<str1<<endl;

    //delete last element (pop back)
    string s="chetan";
    cout<<s<<endl;
    s.pop_back();
    cout<<s<<endl;

    //+ operator
    string z="chetan";
    string b="bhandari";
    z=z+b;
    cout<<z<<endl;

    //reverse
    string str3="abcdef";
    reverse(str3.begin(),str3.end());
    cout<<str3<<endl;
    reverse(str3.begin()+2,str3.end());    //i want from conwards reverse
    cout<<str3<<endl;
}