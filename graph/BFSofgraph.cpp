#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>BFS(vector<int>adj[] , int v){
    vector<int>vis(v,0);
    vis[0] = 1;
    queue<int>q;
    q.push(0);
    vector<int>bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        bfs.push_back(node);
        
        for(auto x :adj[node]){
            if(!vis[x]){
                vis[x] = 1;
                q.push(x);
            }
        }
    }
    return bfs;
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

    vector<int> result = BFS(adj, v);

    for (int x : result) {
        cout << x << " ";
    }
}
