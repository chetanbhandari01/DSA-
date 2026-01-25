#include<iostream>
using namespace std;
int main(){
    int x=5;
    int y=2;
    // cout<<x+y<<endl;
    // cout<<x-y<<endl;
    // cout<<x*y<<endl;

    int reminder=x%y;   //x>y is correct reminder 
    cout<<reminder<<endl;

    int a=2;
    int b=5;
    reminder=a%b;    //if a<b than a%b =a only
    cout<<reminder<<endl;

}
