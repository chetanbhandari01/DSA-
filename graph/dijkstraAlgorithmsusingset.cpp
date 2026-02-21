#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    set<pair<int,int>>st;
    int n = edges.size();
    vector<vector<pair<int,int>>>adj(V);
    vector<int>dist(V,1e9);
    for(int i=0;i<n;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int dis = edges[i][2];
        adj[u].push_back({v,dis});
        adj[v].push_back({u,dis});
    }
    dist[src] =0;
    st.insert({0,src});  //{dis,node}
    while(st.size()>0){
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);
        
        for(auto x: adj[node]){
            int edgeweight = x.second;
            int adjNode = x.first;
            if(dis+edgeweight < dist[adjNode]){
                
                //erase if the existed
                if(dist[adjNode] != 1e9){
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode] = dis+edgeweight;
                st.insert({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}
int main() {

    int V = 4;   // number of vertices
    int src = 0; // source node

    // edges format: {u, v, weight}
    vector<vector<int>> edges = {
        {0,1,4},
        {0,2,1},
        {2,1,2},
        {1,3,1},
        {2,3,5}
    };

    vector<int> result = dijkstra(V, edges, src);

    cout << "Shortest distances from source node " << src << ":\n";

    for(int i = 0; i < V; i++){
        cout << "Node " << i << " -> " << result[i] << endl;
    }

    return 0;
}