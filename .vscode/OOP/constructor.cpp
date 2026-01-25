#include<iostream>
#include<string>
using namespace std;
class bike{
public:
    int tyresize;

    //default constructor
    bike(){
        cout<<"constructor call hau\n";
    }
};
int main(){
    bike tvs;  //object creation //constructor ke caal jaayegi
    bike honda;
}