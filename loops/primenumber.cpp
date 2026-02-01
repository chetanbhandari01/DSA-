#include<iostream>
using namespace std;
int main(){
    int n=13;
    for(int i=2;i<=n-1;i++){
        if(n%i!=0){
            cout<<n<<" is prime number "<<endl;
            break;
        }
    }
}