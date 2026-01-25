#include<iostream>
using namespace std;
class a{
private:       
    int a_ka_private;   
public :       
    int a_ka_protected;  
  
};

class b :virtual public a{  
public:
    int b_ka_public;
    
};
class c:virtual public a{
public:
    int c_ka_public;
};
class d: public b,public c{  //multiple inheritance
public:
    int d_ka_public;
};
int main(){
    b bb;
    d dd;
    
    bb.b_ka_public=32;
    cout<<bb.b_ka_public;
}