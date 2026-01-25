#include<iostream>
using namespace std;
int path(int n){
    if(n==1) return 1;
    if(n==2) return 2; //so man on 2nd stair and he have 2 ways to go 4nd stair than ways are 1 1 or direct 2
    if(n==3) return 3; // 1 1 1 or 1 2 or 2 1   there are 3 ways
    return path(n-1)+path(n-2);
}
int main(){
    int n=6;
    cout<<path(n);
}