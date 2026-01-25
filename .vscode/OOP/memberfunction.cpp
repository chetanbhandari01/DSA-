#include<iostream>
using namespace std;
class player{
private:   
    int score;  //data member can access in class if private also like family
    int health;
public:
    //setter
    void setscore(int s){   //member function
        score = s;
    }
    void sethealth(int h){
        health=h;
    }
    //getter
    int getscore(){
        return score;
    }
    int gethealth(){
        return health;
    }
};
int main(){
    player chetan;
    chetan.setscore(100);
    cout<<chetan.getscore()<<endl;
    chetan.sethealth(1000);
    cout<<chetan.gethealth();
}