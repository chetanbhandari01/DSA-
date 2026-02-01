//price is same or greater than than print 1 
#include<iostream>
using namespace std;
class book{
public:
    string name;
    int price;
    int countbook(int p){
        if(price<=p) return 1;
        else return 0;
    }
    
};
int main(){
    book harrypotter;
    harrypotter.price=200;
    cout<<harrypotter.countbook(200);
}