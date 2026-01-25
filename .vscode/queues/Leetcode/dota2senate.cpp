#include<iostream>
#include<string>
#include<queue>
using namespace std;
string predictPartyVictory(string senate) {
    queue<int>q; //queue
    queue<int>r; //randiant
    queue<int>d;  //dire
    for(int i=0;i<senate.size();i++){
        q.push(i);
        if(senate[i]=='R') r.push(i);
        else d.push(i);
    }
    while(q.size()>1){
        if(senate[q.front()]=='X') q.pop();
        else if(senate[q.front()]=='R'){
            if(d.size()==0) return "Radiant";  //check for victory
            else {  //take rights of next Dire
                senate[d.front()]='X';
                d.pop();
                //work done
                int a=q.front();
                q.pop();
                q.push(a);
                int b=r.front();
                r.pop();
                r.push(b);
            }
        }
        else{
            if(r.size()==0) return "Dire";
            else {
                senate[r.front()]='X';
                r.pop();
                //work done 
                int a=q.front();    //q la cycle
                q.pop();
                q.push(a);
                int b=d.front();
                d.pop();
                d.push(b);
            }
        }
    }
    if(senate[q.front()]=='R')return "Radiant";
    else return "Dire";
}
int main(){
    cout<<predictPartyVictory("RDRRRD");
}