#include<iostream>
using namespace std;
class car{
public:   
    int speed;
    int size;
    virtual void calculatemilage()=0; // pure virtual function
    virtual void refuel()=0;       
};

class bike :public car{  
public:
    void calculatemilage(){
        cout<<"calculate milage\n";
    }
    void refuel(){
        cout<<"refuel\n";
    }
};
int main(){
    //car ko object nahi banna sakta because pure virtual mean abstract hai tu object nahi banana
    bike a;
    a.calculatemilage();
    a.refuel();
}