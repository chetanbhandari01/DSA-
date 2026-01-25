//leetcode 204 good question 
//sieve of eratosthenesis
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
void fillsieve(vector<int>&sieve){
    int n=sieve.size()-1;
    for(int i=2;i<=sqrt(n);i++){
        for(int j=i*2;j<=n;j+=i){
            sieve[j]=0;
        }
    }
}
int countPrimes(int n) {
    if(n<=2) return 0;
    int count=0;
    n=n-1;
    vector<int>sieve(n+1,1); //1 means prime, 0 means not prime
    fillsieve(sieve);
    sieve[0]=0;  //0 and 1 are not prime number
    sieve[1]=0;
    for(int i=2;i<=n;i++){
        if(sieve[i]==1) count++;
    }
    return count++;
}
int main(){
    cout<<countPrimes(5000000);
}


//this code run time exceeded

// bool isprime(int n){
//     if(n==1) return false ;
//     for(int i=2;i<=sqrt(n);i++){
//         if(n%i==0) return false ;
//     }
//     return true;
// }
// int countPrimes(int n) {
//     int count=0;
//     for(int i=2;i<n;i++){
//         if(isprime(i)) count++;
//     }
//     return count;
// }