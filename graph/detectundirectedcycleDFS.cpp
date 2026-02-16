#include<iostream>
#include<vector>
using namespace std;
bool isdetect(vector<vector<int>>&adj,vector<int>&vis,int node,int parent){
    vis[node] = 1;
    for(auto x:adj[node]){
        if(vis[x]==0){
            if(isdetect(adj,vis,x,node)==true){
                return true;
            }
        }
        else if(x != parent){
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    int n = edges.size();
    
    // adjacency list 
    vector<vector<int>>adj(V);
    for(int i=0;i<n;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            if(isdetect(adj,vis,i,-1)) return true;
        }
    }
    return false;
    
}
int main() {

    vector<vector<int>> grid = {
        {0, 1}, {0, 2}, {1, 2}, {2, 3}
    };

    bool result = isCycle(4,grid);

    cout << result << endl;

    return 0;
}