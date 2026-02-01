#include<iostream>
using namespace std;
class complexnumber{
public:
    int real;
    int imaginary;

    complexnumber operator +(complexnumber &c1){  //function overloading
        complexnumber c3;
        c3.imaginary=c1.imaginary+this->imaginary; //c2 imaginary =imaginary
        c3.real=c1.real+this->real;
        return c3;
    }
    complexnumber operator -(complexnumber &c1){
        complexnumber c3;
        c3.imaginary=c1.imaginary-this->imaginary; 
        c3.real=c1.real-this->real;
        return c3;
    }
};
int main(){
    complexnumber a1,a2;
    a1.imaginary=-5;
    a2.imaginary=2;
    a1.real=3;
    a2.real=1;
    complexnumber a3=a2 +a1;
    cout<<"real : "<<a3.real<<" "<<"imaginary : "<<a3.imaginary<<endl;

    complexnumber a4=a2 - a1;
    cout<<"real : "<<a4.real<<" "<<"imaginary : "<<a4.imaginary<<endl;
}