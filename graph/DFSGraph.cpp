#include<iostream>
#include<vector>
using namespace std;
void dfsG(int node ,vector<vector<int>>& adj,vector<int>&dfs,vector<int>&vis){
    vis[node] = 1;
    dfs.push_back(node);
    
    //traverse all list
    for(auto x: adj[node]){
        if(vis[x]==0){
            dfsG(x,adj,dfs,vis);
        }
    }
}
vector<int> dfs(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int>vis(n,0);
    vector<int>dfs;
    int start = 0;
    dfsG(start,adj,dfs,vis);
    return dfs;
}
int main(){
    int v, e;
    cin >> v >> e;          // number of vertices and edges

    vector<int> adj[v];

    for (int i = 0; i < e; i++) {
        int u, vtx;
        cin >> u >> vtx;
        adj[u].push_back(vtx);
        adj[vtx].push_back(u);   // remove this line if graph is directed
    }
    vector<int> result = dfs(adj);

    for (int x : result) {
        cout << x << " ";
    }
}