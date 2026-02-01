#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cpm(vector<int>&a,vector<int>&b){
    return a[1] >b[1];
}
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    int n=boxTypes.size();
    sort(boxTypes.begin(),boxTypes.end(),cpm);
    int profit =0;
    for(int i=0;i<n;i++){
        if(boxTypes[i][0] <=truckSize){
            profit += boxTypes[i][0]*boxTypes[i][1];
            truckSize -= boxTypes[i][0];
        }
        else {
            profit +=truckSize*boxTypes[i][1];
            truckSize =0;
        }
        if(truckSize==0) break;
    }
    return profit;
}
int main(){
    vector<vector<int>> boxTypes={{5,10},{2,5},{4,7},{3,9}};
    int trucksize=10;
    cout<<maximumUnits(boxTypes,trucksize);
}