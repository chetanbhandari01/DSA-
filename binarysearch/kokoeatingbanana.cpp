#include<iostream>
#include<vector>
using namespace std;
bool check(int speed,vector<int>&piles,int hour){  //mid==speed
    int n=piles.size();
    long long count=0;
    for(int i=0;i<n;i++){
        if(speed>=piles[i])  count++;  //speed is 30 and piles are 11 than time is 1 hour required
        else if(piles[i]%speed==0){
            count +=(long long)piles[i]/speed;  //means piles 8 and speed 4 and reminder is 0 than true and time is 2 hour
        }
        else {
            count +=(long long)(piles[i]/speed +1);  //mean p=7 and s=4 than 7/4 +1 =2 time 2 hour required
        }
    }
    if(count>(long long)hour) return false;
    else return true;
}
int eatingspeed(vector<int>&piles,int hour){
    int n=piles.size();
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(max<piles[i])  max=piles[i];
    }
    int lo=1;  //minimum 
    int hi=max;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid,piles,hour)){
            ans=mid;  
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int>piles;
    piles.push_back(3);
    piles.push_back(6);
    piles.push_back(7);
    piles.push_back(11);
    int hour=8;
    cout<<eatingspeed(piles,hour);

}