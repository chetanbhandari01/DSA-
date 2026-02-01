//2521 distinct prime factors of product of array
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
void fillsieve(vector<bool>&sieve){
    int n=sieve.size()-1;
    for(int i=2;i<=sqrt(n);i++){
        for(int j=i*2;j<=n;j+=i){
            sieve[j]=0;
        }
    }
}
int distinctPrimeFactors(vector<int>& nums) {
    int n=nums.size();
    int mx=-1;
    for(int i=0;i<n;i++){
        mx=max(mx,nums[i]);
    }
    vector<bool>sieve(mx+1,1);
    if(mx+1>0) sieve[0]=0;
    if(mx+1>1) sieve[1]=0;
    fillsieve(sieve);
    vector<int>primes;
    for(int i=2;i<=mx;i++){
        if(sieve[i]==1){
            primes.push_back(i);
        }
    }
    vector<bool> taken(primes.size(),0);
    for(int i=0;i<nums.size();i++){
        int ele=nums[i];
        for(int j=0;j<primes.size();j++){
            if(primes[j]>ele) break;
            if(ele % primes[j]==0) taken[j]=1;
        }
    }
    int count=0;
    for(int i=0;i<taken.size();i++){
        if(taken[i]==1) count++;
    }
    return count;
}
int main(){
    vector<int> v={2,4,3,7,10,6};
    cout<<distinctPrimeFactors(v);
}
