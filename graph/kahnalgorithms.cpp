#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//topological same hai 
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    int n = edges.size();
    vector<vector<int>>adj(V);
    for(int i=0;i<n;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    vector<int>indegree(V,0);
    for(int i=0;i<V;i++){
        for(auto x:adj[i]){
            indegree[x]++;
        }
    }
    
    queue<int>q;
    for(int i=0;i<V;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(q.size()>0){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto x:adj[node]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
    return topo;
}
int main() {

    vector<vector<int>> grid = {
        {0,1},
        {1,2},
        {0,2},
        {2,3}
    };

    vector<int>ans = topoSort(4,grid);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}