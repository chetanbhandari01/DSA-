#include<iostream>
using namespace std;  //like pre IN post
void hanoi(int n,char s,char h,char d){    //s=source,d=destination,h=helper
    if(n==0) return ;
    hanoi(n-1,s,d,h);
    cout<<s<<"->" <<d<<endl;
    hanoi(n-1,h,s,d);
}
int main(){
    int n=3;
    hanoi(n,'A','B','C');
}