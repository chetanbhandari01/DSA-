#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
    int n = edges.size();
    vector<vector<int>>adj(V);
    //adjanceny matrix
    for(int i=0;i<n;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //
    queue<pair<int,int>>q;
    vector<int>dis(V,1e9);
    dis[src] =0;
    q.push({src,0});
    while(q.size()>0){
        int node = q.front().first;
        int wt = q.front().second;
        q.pop();
        for(auto x:adj[node]){
            if(dis[node]+wt < dis[x]){
                dis[x] = wt+1;
                q.push({x,wt+1});
            }
        }
    }
    for(int i=0;i<dis.size();i++){
        if(dis[i]==1e9){
            dis[i] = -1;
        }
    }
    return dis;
} 
int main(){

    int V = 6;
    int E = 7;

    vector<vector<int>> edges = {
        {0,1,2},
        {0,4,1},
        {1,2,3},
        {4,2,2},
        {2,3,6},
        {4,5,4},
        {5,3,1}
    };

    vector<int> result = shortestPath(V, edges,0);

    cout << "Shortest distances from source (0):\n";
    for(int i = 0; i < V; i++){
        cout << "Node " << i << " -> " << result[i] << endl;
    }
    return 0;
}