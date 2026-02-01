#include<iostream>
using namespace std;
int factorial(int f){
    int fact=1;
    for(int i=2;i<=f;i++){
        fact*=i;
    }
    
    return fact ;
}
int combination(int n,int r){
    int ncr=factorial(n)/(factorial(r)*factorial(n-r));
    return ncr;
}
int permutation(int n,int r){
    int npr=factorial(n)/(factorial(n-r));
    return npr;
}
int main(){
    int n;
    int r;
    cout<<"enter n : ";
    cin>>n;
    cout<<"enter r : ";
    cin>>r;
    int ncr=combination(n,r);
    int npr=permutation(n,r);
    cout<<ncr<<endl;
    cout<<npr;
    
}