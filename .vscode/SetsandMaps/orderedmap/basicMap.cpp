#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,int>m;
    m[4]=20;
    m[3]=40;
    m[1]=10;
    for(auto x :m){
        cout<<x.second<<" ";  //printed on based on key in sorting way
    }
}