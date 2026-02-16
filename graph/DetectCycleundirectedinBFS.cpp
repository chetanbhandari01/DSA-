#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool isdetect(vector<vector<int>>&adj,vector<int>&vis,int src){
    vis[src] = 1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    
    while(q.size()>0){
        int node = q.front().first;
        int parentnode = q.front().second;
        q.pop();
        
        for(auto x:adj[node]){
            if(vis[x]==0){
                vis[x] =1;
                q.push({x,node});
            }
            else if(parentnode != x){
                return true;
            }
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
            if(isdetect(adj,vis,i)) return true;
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