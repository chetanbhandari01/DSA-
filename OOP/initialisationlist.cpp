#include<iostream>
#include<string>
using namespace std;
class bike{
public:
    static int noofbikes;  
    int tyresize;
    int enginesize;

    bike(int ts,int es) : tyresize(ts),enginesize(es){  //initalisation list
    }
        
};
int main(){
    bike tvs(12,100);  //object creation //constructor ke call jaayegi
    bike honda(21,102);
    cout<<tvs.tyresize<<" " <<tvs.enginesize<<endl;
    cout<<honda.tyresize<<" " <<honda.enginesize<<endl;
}