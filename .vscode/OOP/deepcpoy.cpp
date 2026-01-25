#include<iostream>
using namespace std;
class A{
    public:
    int d;
    int c;

};
int main(){
    A a;
    //A b=a;   //  check it 
    a.d=22;
    a.c=332;
    A b=a;   //check it
    cout<<b.c;

}
