#include<iostream>
#include<string>
using namespace std;
class vechile{  //Base class ,Parent class 
public:
    int tyresize;
    int enginesize;
    string name;
};
class car : public vechile{  //car is child of vechile
public:
    int steeringsize;
};
class bike : public vechile{  //derived class ,child class 
public:
    int handlesize;

};
int main(){
    bike honda;
    honda.handlesize=20;
    honda.name="honda";
    honda.tyresize=34;
    honda.enginesize=122;
    cout<<honda.enginesize;
}