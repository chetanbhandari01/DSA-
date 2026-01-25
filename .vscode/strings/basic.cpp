#include<iostream>
#include<string>
using namespace std;
int main(){
    char str[]={'a','b','c','d'};
    for(int i=0;i<4;i++){
        cout<<str[i];
    }
    cout<<endl;
    string s="chetan";
    cout<<s<<endl;

    //taking input from user
    string a;     
    cout<<"enter a string : ";
    getline(cin,a);
    cout<<a;
}