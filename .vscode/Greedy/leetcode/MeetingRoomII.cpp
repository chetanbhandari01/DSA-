//253
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minMeetingRooms(vector<vector<int>>& intervals) {
    vector<int>starting;
    vector<int>ending;
    for(int i=0;i<intervals.size();i++){
        starting.push_back(intervals[i][0]);
        ending.push_back(intervals[i][1]);
    }
    sort(starting.begin(),starting.end());
    sort(ending.begin(),ending.end());
    int i=0;
    int j=0;
    int room = 0;
    int ans = 0;
    while(i<starting.size() && j<ending.size()){
        if(starting[i]<ending[j]){ //meeting started room allocate
            i++; 
            room++;
            ans = max(ans,room);
        }
        else if(starting[i]>ending[j]){
            j++;
            room--;
        }
        else {
            j++;
            i++;
        }
    }
    return room;
}
int main(){
    vector<vector<int>>interval = {{1,10},{2,7},{3,19},{8,12},{10,20},{11,30}};
    cout<<minMeetingRooms(interval);
}