#include<iostream>
using namespace std;
class a{
private:       //cant be accessed ,cant be inherited 
    int a_ka_private;   
protected:       //cant be accessed ,can be inherited
    int a_ka_protected;  
public:          //can be accessed ,can be inherited
    int a_ka_public;  
};

class b :public a{  //a se ju bhi aaye tu b keliye public rahe
public:
    int b_ka_public;
    void show(){
        a_ka_protected=20;
    }
};
int main(){
    b bb;
    bb.a_ka_public=22;
    
    bb.b_ka_public=32;
    cout<<bb.b_ka_public;
}