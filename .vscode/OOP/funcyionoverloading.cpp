#include<iostream>
#include<string>
using namespace std;
class bike{
public:
    int tyresize;
    int enginesize;
    bike(int ts,int es) :tyresize(ts),enginesize(es){}
    bike(int ts):tyresize(ts),enginesize(100){}
    bike():tyresize(32),enginesize(220){}

};
// void add (int a,int b){  //function overloading
//     cout<<a+b<<endl;
// }
// void add(int a){
//     cout<<10+a<<endl;
// }
int main(){
    // add(1,2);
    // add(5);
    bike tvs(12,300);
    cout<<tvs.tyresize<<" "<<tvs.enginesize<<endl;
    bike honda(34);
    cout<<honda.tyresize<<" "<<honda.enginesize<<endl;
    
}