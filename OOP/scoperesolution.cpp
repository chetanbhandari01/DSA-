#include<iostream>
using namespace std;
class player{
private:
    int health;
    int score;
public:
    void sethealth(int health){
        player::health=health; //player ki health=health , :: means scope resolution operator
    }
    void setscore(int score){
        this->score =score;  // this-> matlab player ki score =score  
    }
    int gethealth(){
        return health;
    }
    int getscore(){
        return score;
    }
};
int main(){
    player chetan;
    chetan.sethealth(90);
    cout<<chetan.gethealth()<<endl;
    chetan.setscore(90);
    cout<<chetan.getscore()<<endl;
}