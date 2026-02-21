#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void dfs(int node ,vector<vector<pair<int,int>>>&adj,vector<int>&vis,stack<int>&st){
    vis[node] =1;
    for(auto x: adj[node]){
        int v = x.first;
        if(vis[v]==0){
            dfs(v,adj,vis,st);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    int n = edges.size();
    vector<vector<pair<int,int>>>adj(V);
    for(int i=0;i<n;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
    }
    stack<int>st;
    vector<int>vis(V,0);
    //O(N + E) tc
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            dfs(i,adj,vis,st);
        }
    }
    
    //step 2 the distance array
    vector<int>dis(V,1e9);
    dis[0] = 0;  //src node scr is 0 know
    // O(N + E)
    while(st.size()>0){
        int node  = st.top();
        st.pop();
        
        for(auto x: adj[node]){
            int v = x.first;
            int wt = x.second;
            
            if(dis[node]!=1e9 && dis[node] + wt < dis[v]){
                dis[v] = dis[node]+wt;
            }
        }
    }
    for(int i = 0; i < V; i++){
        if(dis[i] == 1e9) dis[i] = -1;
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

    vector<int> result = shortestPath(V, E, edges);

    cout << "Shortest distances from source (0):\n";
    for(int i = 0; i < V; i++){
        cout << "Node " << i << " -> " << result[i] << endl;
    }

    return 0;
}