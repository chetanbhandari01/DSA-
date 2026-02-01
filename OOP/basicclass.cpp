#include<iostream>
using namespace std;
class player{
public:
    int score;
    string name;
    void showname(){  //member function
        cout<<"name is :"<<name;
    }
};

int main(){
    player amit;
    amit.score=100;
    amit.name="Chetan";
    // cout<<amit.name<<endl;
    // cout<<amit.score<<endl;
    amit.showname();
}
