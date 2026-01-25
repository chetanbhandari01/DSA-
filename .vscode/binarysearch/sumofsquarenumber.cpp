//leetcode 633
#include<iostream>
#include<math.h>
using namespace std;
// bool isperfectsquare(int n){
//     int root=sqrt(n);
//     if(root*root==n) return true;
//     else return 0;
// }
// bool squaresum(int c){
//     int x=0;
//     int y=c;
//     while(x<=y){
//         if(isperfectsquare(x) && isperfectsquare(y)){
//             return true;
//         }
//         else if(!isperfectsquare(y)){
//             y=(int)sqrt(y)*(int)sqrt(y);
//             x=c-y;    //x+y=c
//         }
//         else {
//             x=((int)sqrt(x)+1)*((int)sqrt(x)+1);
//             y=c-x;
//         }
        
//     }
//     return false;
// }

//optimize way
bool squaresum(int n){
    long long x=0;
    long long y=(long long)sqrt(n);
    
    while(x<=y){
        long long sum=x*x+y*y;
        if(sum==n){
            return true;
        }
        else if(sum<n) {
            x++;
        }
        else{
            y--;
        }
    }
    return false;
}
int main(){
    int c=5;
    cout<<squaresum(c);
}