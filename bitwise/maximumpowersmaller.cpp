//given integer n ,find the maximum power of two that is smaller than n .
#include<iostream>
using namespace std;
int set_bit2(int n){
    int temp=n;
    n=n | (n >> 1);
    n=n | (n >> 2);
    n=n | (n >> 4);
    n=n | (n >> 8);
    n=n | (n >> 16);

    return (n+1)>>1;
}
// void set_bit(int n){
//     int temp;
//     while(n !=0){
//         temp=n;
//         n=(n & n-1);
//     }
//     cout<<temp;
//     return ;
// }
int main(){
    //set_bit(24);
    cout<<set_bit2(24);
}