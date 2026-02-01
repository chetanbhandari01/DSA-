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
int playerscore(player a,player b){   //
    return a.getscore()+b.getscore();
}
player getmaxscore(player a,player b){  //return class 
    if(a.getscore()>b.getscore()){
        return a;
    }
    else return b;
}
int main(){
    player chetan;
    player raghav;
    chetan.sethealth(90);
    raghav.sethealth(95);
    chetan.setscore(90);
    raghav.setscore(100);
    cout<<playerscore(chetan,raghav)<<endl;
    //we dont return class as than we make player and store
    player sanket=getmaxscore(chetan,raghav);
    cout<<sanket.getscore()<<endl;
}