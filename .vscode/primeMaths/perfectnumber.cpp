//507 perfect number
#include<iostream>
#include<cmath>
using namespace std;
bool checkPerfectNumber(int num) {
    int sum=0;
    for(int i=1;i<sqrt(num);i++){
        if(num%i==0) {
            sum+=i;
        }
    }
    for(int i=sqrt(num);i>1;i--){
        if(num%i==0){
            sum+=num/i;
        }
    }
    //sum checking
    if(sum==num) return true;
    else return false;
}
int main(){
    cout<<checkPerfectNumber(28);
}
