#include<iostream>
using namespace std;
class player {
private:
    int health;
    int score;
public:
    void sethealth(int health){
        this->health=health;
    }
    int gethealth(){
        return health;
    }
};
class gun{
private:
    int ammo;
public :
    void setammo(int ammo){
        this->ammo=ammo;
    }
    int getammo(){
        return ammo;
    }
};
int main(){
    player chetan;
    gun ak;
    chetan.sethealth(98);
    ak.setammo(23);
    cout<<chetan.gethealth()<<endl;
    cout<<ak.getammo()<<endl;
}