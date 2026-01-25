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
    player raghav;
    chetan.sethealth(90);
    raghav.sethealth(95);
    chetan.setscore(90);
    raghav.setscore(100);
    
    player *yash=new player; //help of pointers 
    yash->setscore(89);  //this syntax of declearing
    cout<<yash->getscore()<<endl;
    yash->sethealth(69);
    player players[3]={raghav,chetan,*yash};
    for(int i=0;i<3;i++){
        cout<<players[i].gethealth()<<endl;
    }
}