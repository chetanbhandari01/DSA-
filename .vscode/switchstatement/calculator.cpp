#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"enter two number : ";
    char ch;
    cin>>a>>ch>>b;
    switch(ch){
        case '+':
            cout<<a+b;
            break;
        case '-' :
            cout<<a-b;
            break;
        case '*' :
            cout<<a*b;
            break;
        case '/' :
            cout<<a/b;

    }
}