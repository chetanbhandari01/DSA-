#include<iostream>
using namespace std;
class car{ 
public:          
    int a_ka_public;  
    virtual void show(){
        cout<<"mein 'car' ka show hu\n";
    }
};

class bike :public car{  
public:
    int b_ka_public;
    void show(){  //this overriding because already show function exist 
        cout<<"mein 'bike' ka show hu\n";
    }
};
int main(){
    bike b;
    b.show();  //bike ko call kare ga 
    b.car:: show(); //a ko call keya using scope resolution operator 

    //or pointer also helpes
    car *c;
    c=&b;
    c->show();  //pointer ko calls using -> arrow //c ne b ko call karna chahiye par
    //than we take help of virtual function to call b
    //tu a ke void function ko virtual void show write karo phir b ko call jayeegi
}