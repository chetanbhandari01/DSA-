#include<iostream>
using namespace std;
int main(){
    int x=5;
    int* p=&x;
    cout<<&x<<endl;
    cout<<p<<endl;

    char ch= 'g';
    char* ptrv= &ch;
    cout<<&ch<<endl;
    cout<<ptrv<<endl;

    bool xh=true;
    bool* ptr= &xh;
    cout<<&xh<<endl;
    cout<<ptr<<endl;

}
