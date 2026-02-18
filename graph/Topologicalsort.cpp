#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
    vis[node] =1;
    for(auto x:adj[node]){
        if(vis[x]==0){
            dfs(x,vis,st,adj);
        }
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    int n = edges.size();
    vector<vector<int>>adj(V);
    for(int i=0;i<n;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    vector<int>vis(V,0);
    stack<int>st;
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            dfs(i,vis,st,adj);
        }
    }
    vector<int>ans;
    while(st.size()>0){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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