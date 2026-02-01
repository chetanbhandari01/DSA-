#include<iostream>
using namespace std;
int count_setbit(int n){
    int count=0;
    while(n>0){
        count++;
        n=(n & n-1);
    }
    return count;
}
int main(){
    cout<<count_setbit(4);
}

// int main(){
//     int n=13;
//     cout<<__builtin_popcount(n);   //built in function
// }