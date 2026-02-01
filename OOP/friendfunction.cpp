#include<iostream>
using namespace std;
class A{
private:
    int a_private=10;
public:
    friend void show(A &a);

};
void show(A &a){  //different function and accessing private 
    cout<<a.a_private<<endl;
}
int main(){
    A a;
    show(a);
}