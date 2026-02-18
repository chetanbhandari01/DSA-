#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool dfs(int node,vector<int>&vis,vector<int>&pathvis,vector<vector<int>>&adj){
    vis[node] = 1;
    pathvis[node] = 1;
    
    //traverse
    for(auto x:adj[node]){
        if(vis[x]==0){
            if(dfs(x,vis,pathvis,adj)==true){
                return true;
            }
        }
        //visited hai and pathvis already visit keli hai tar cycle hai true
        else if(pathvis[x]==1 && vis[x]==1){
            return true;
        }
    }
    
    pathvis[node] =0;
    return false;
}
bool isCyclic(int V, vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int>vis(V,0);
    vector<int>pathvis(V,0);
    vector<vector<int>>adj(V);

    for(int i=0;i<n;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            if(dfs(i,vis,pathvis,adj)==true)return true;
        }
    }
    return false;
}
int main() {

    vector<vector<int>> grid = {
        {0,1},
        {1,2},
        {0,2},
        {2,3}
    };

    cout<<isCyclic(4,grid);

    return 0;
}