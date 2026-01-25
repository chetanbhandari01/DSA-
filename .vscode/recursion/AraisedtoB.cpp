#include<iostream>
using namespace std;
// int power(int a,int b){
//     // if(a==0) return 0;
//     if(b==0) return 1;
//     int sum = (a*power(a,b-1));
//     return sum;
// }

//optimize way
int power(int x,int y){
    if(y==0) return 1;
    int ans=power(x,y/2);
    if(y%2==0){
        return ans*ans;
    }
    else return ans*ans*x;
}
int main(){
    int a=5;
    int b=2;
    cout<<power(a,b);
}

