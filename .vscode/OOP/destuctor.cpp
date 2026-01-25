#include<iostream>
#include<string>
using namespace std;
class bike{
public:
    int tyresize;
    int enginesize;
    //default constructor
    bike(int tyresize,int enginesize){  //bike(int n) is parametrised constructor
        this->tyresize=tyresize;
        this->enginesize=enginesize;
    }
    ~bike(){
        cout<<"destuctor call hau\n";  //
    }
};
int main(){
    bike tvs(12,100);  //object creation //constructor ke call jaayegi
    bike honda(21,102);
    cout<<tvs.tyresize<<" " <<tvs.enginesize<<endl;
    cout<<honda.tyresize<<" " <<honda.enginesize<<endl;
}