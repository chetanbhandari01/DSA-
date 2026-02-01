#include<iostream>
#include<vector>
using namespace std;
bool check(int mid,vector<int>&weight,int days){
    int n=weight.size();
    int m=mid;
    int count=1;
    for(int i=0;i<n;i++){
        if(m>=weight[i]){
            m-=weight[i];
        }
        else{
            count++;
            m=mid;
            m-=weight[i];
        }
    }
    if(count>days) return false;
    else return true;
}
int shipweight(vector<int>&weight ,int days){
    int n=weight.size();
    int max=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        if(max<weight[i]){
            max=weight[i];
        }
        sum+=weight[i];
    }
    int lo=max;
    int hi=sum;
    int mincapacity=sum;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(check(mid,weight,days)){
            mincapacity=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return mincapacity;
}
int main(){
    vector<int>weight;
    weight.push_back(3);
    weight.push_back(2);
    weight.push_back(2);
    weight.push_back(4);
    weight.push_back(1);
    weight.push_back(4);
    cout<<shipweight(weight,3);
}