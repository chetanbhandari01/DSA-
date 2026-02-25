#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minimumMultiplications(vector<int>& arr, int start, int end) {
    vector<int>dist(100000,1e9);
    int n = arr.size();
    if(start == end) return 0;
    queue<pair<int,int>>q;
    dist[start] =0;
    q.push({start ,0}); // node , steps
    while(q.size()>0){
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        for(int i=0;i<n;i++){
            int num = (arr[i] * node)%100000;
            if(steps+1 < dist[num]){
                dist[num] = steps+1;
                if(num == end) return steps+1;
                q.push({num,steps+1});
            }
        }
    }
    return -1;
}
int main(){
    vector<int>arr = {2, 5, 7};
    int start =3;
    int end = 30;
    cout<<minimumMultiplications(arr,start,end);
}
