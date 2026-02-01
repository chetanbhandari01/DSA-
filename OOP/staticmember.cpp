#include<iostream>
#include<string>
using namespace std;
class bike{
public:
    static int noofbikes;  //this belong to class
    int tyresize;
    int enginesize;
    //default constructor
    bike(int tyresize,int enginesize){  //bike(int n) is parametrised constructor
        this->tyresize=tyresize;
        this->enginesize=enginesize;
    }
    static void increasebike(){
        noofbikes++;
    }

};
int bike::noofbikes=10;
int main(){
    bike tvs(12,100);  //object creation //constructor ke call jaayegi
    bike honda(21,102);
    tvs.increasebike();
    cout<<tvs.noofbikes<<endl;
    cout<<honda.noofbikes<<endl;

    honda.increasebike();
    cout<<tvs.noofbikes<<endl;
    cout<<honda.noofbikes<<endl;

    bike::increasebike();
    cout<<tvs.noofbikes<<endl;
    cout<<honda.noofbikes<<endl;
    // cout<<tvs.tyresize<<" " <<tvs.enginesize<<endl;
    // cout<<honda.tyresize<<" " <<honda.enginesize<<endl;
}