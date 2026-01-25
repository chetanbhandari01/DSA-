#include<iostream>
#include<vector>
using namespace std;
bool check (long long mid,vector<int>&time,int totaltrip){
    long long trip=0;
    int n=time.size();
    //1 2 3 mid hour =2 than 
    for(int i=0;i<n;i++){
        trip+=mid/time[i];
    }
    if(trip<totaltrip) return false;
    else return true;
}
long long minimumtime(vector<int>&time ,int totaltrip){
    int n=time.size();
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(max<time[i]) max=time[i];
    }
    long long lo=1;
    long long hi= (long long)max*(long long)totaltrip;
    long long ans=-1;
    while(lo<=hi){
        long long mid=lo+(hi-lo)/2;
        if(check(mid,time,totaltrip)){
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
    vector<int>time;
    time.push_back(8);
    time.push_back(7);
    time.push_back(9);
    time.push_back(10);
    cout<<minimumtime(time,1);
}