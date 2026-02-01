#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(vector<int>&a,vector<int>&b){
    return a[0]<b[0];
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end(),cmp);  //end point par sorting 
    vector<vector<int>>result;
    int n = intervals.size();
    result.push_back(intervals[0]);
    for(int i=1;i<n;i++){
        vector<int> curr = intervals[i];
        if(curr[0] <= result[result.size()-1][1]){
            //curr.end >= last.start  --> overlapping
            result[result.size()-1][0] = min(result[result.size()-1][0] , curr[0]);
            result[result.size()-1][1] = max(result[result.size()-1][1] , curr[1]);
        }
        else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}
int main(){
    vector<vector<int>>arr={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>ans=merge(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans.size();j++){
            cout<<ans[i][j]<<" ";
        }
    }
}