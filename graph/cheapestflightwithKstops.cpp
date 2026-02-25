#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    int m = flights.size();
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++){
        int u = flights[i][0];
        int v = flights[i][1];
        int cost = flights[i][2];
        adj[u].push_back({v,cost});
    }
    queue<pair<int,pair<int,int>>>q;
    vector<int>dist(n,1e9);
    q.push({0,{src,0}});
    dist[src] = 0;
    while(q.size()>0){
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();
        if(stops > k) continue;
        for(auto x:adj[node]){
            int adjNode = x.first;
            int adjcost = x.second;
            if(cost+adjcost < dist[adjNode] && stops <= k){
                dist[adjNode] = cost+adjcost;
                q.push({stops+1,{adjNode,dist[adjNode]}});
            }
        }
    }
    if(dist[dst]==1e9) return -1;
    return dist[dst];
}
int main(){
    int n =4;
    vector<vector<int>>grid ={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0;
    int dst =3;
    int k =1;
    cout<<findCheapestPrice(n,grid,src,dst,k);
}