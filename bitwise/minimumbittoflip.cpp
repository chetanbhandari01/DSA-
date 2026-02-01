//calculate the minimum number of bit flip to convert from one number to another
#include<iostream>
using namespace std;
int main(){
    int x=23;
    int y=31;
    cout<<__builtin_popcount(x^y);
}