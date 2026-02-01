#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
int findMinArrowShots(vector<vector<int>>& points) {
    int n= points.size();
    sort(points.begin(),points.end(),cmp);
    int lastEndtime = points[0][1];
    int count=0;
    for(int i=1;i<n;i++){
        if(lastEndtime >= points[i][0]){
            count++;
            lastEndtime = min(points[i][1],lastEndtime);
        }
        else {
            lastEndtime = points[i][1];
        }
    }
    int ans = n-count;
    return ans;
}
int main(){
    vector<vector<int>>intervals={{1,3},{2,6},{8,10},{15,18}};
    cout<<findMinArrowShots(intervals);
}
