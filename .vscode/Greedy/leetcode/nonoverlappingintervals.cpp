#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(),intervals.end(),cmp);
    int lastEndtime = intervals[0][1];
    int count=0;
    for(int i=1;i<n;i++){
        if(lastEndtime > intervals[i][0]){
            count++;
        }
        else{
            lastEndtime = intervals[i][1];
        }
    }
    return count;
}
int main(){
    vector<vector<int>>intervals={{1,3},{2,6},{8,10},{15,18}};
    cout<<eraseOverlapIntervals(intervals);
}