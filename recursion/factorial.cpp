#include<iostream>
using namespace std;
int factorial(int x){
    if(x==0) return 1;
    if(x==1) return 1;
    int result = (x)*factorial(x-1);
    return result;
}
int main(){
    int x=5;
    for(int i=1;i<=x;i++){    //list of factorial 
        cout<<factorial(i)<<endl;
    }
}