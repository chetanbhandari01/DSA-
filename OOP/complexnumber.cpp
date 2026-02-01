//using friend function
#include<iostream>
using namespace std;
class complexnumber{
public:
    int real;
    int imaginary;

    friend complexnumber operator +(complexnumber &c1,complexnumber &c2); 
    friend complexnumber operator -(complexnumber &c1,complexnumber &c2); 
};
complexnumber operator +(complexnumber &c1,complexnumber &c2){
    complexnumber c3;
    c3.imaginary=c1.imaginary+c2.imaginary; 
    c3.real=c1.real+c2.real;
    return c3;
}
complexnumber operator -(complexnumber &c1,complexnumber &c2){
    complexnumber c3;
    c3.imaginary=c1.imaginary-c2.imaginary; 
    c3.real=c1.real-c2.real;
    return c3;
}
int main(){
    complexnumber a1,a2;
    a1.imaginary=5;
    a2.imaginary=2;
    a1.real=3;
    a2.real=1;
    complexnumber a3=a1+a2;
    cout<<"real : "<<a3.real<<" "<<"imaginary : "<<a3.imaginary<<endl;

    complexnumber a4=a1 - a2;
    cout<<"real : "<<a4.real<<" "<<"imaginary : "<<a4.imaginary<<endl;
}