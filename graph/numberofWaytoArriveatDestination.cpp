#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int countPaths(int n, vector<vector<int>>& roads) {
    int m = roads.size();
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++){
        int u = roads[i][0];
        int v = roads[i][1];
        int time = roads[i][2];
        adj[u].push_back({v,time});
        adj[v].push_back({u,time});
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
    vector<long long>dist(n,LLONG_MAX);
    vector<int>ways(n,0);
    q.push({0,0});  //dist,node
    dist[0] =0;
    ways[0] =1;
    int mod = (int)(1e9+7);
    while(q.size()>0){
        int node = q.top().second;
        long long time = q.top().first;
        q.pop();
        for(auto x:adj[node]){ 
            int adjnode = x.first;
            int adjtime = x.second;
            //this is first time i am coming 
            long long newtime =time+adjtime; 
            if(newtime<dist[adjnode]){
                dist[adjnode] = time +adjtime;
                q.push({dist[adjnode],adjnode});
                ways[adjnode] = ways[node];
            }
            //already taken in queue on need to repeated only count ways
            else if(newtime == dist[adjnode]){
                ways[adjnode] = (ways[adjnode]+ways[node])%mod;
            }
        }
    }
    return ways[n-1];
}
int main(){
    int n = 7;
    vector<vector<int>>arr ={{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{2,5,1},{0,4,5}};
    cout<<countPaths(n,arr);
}