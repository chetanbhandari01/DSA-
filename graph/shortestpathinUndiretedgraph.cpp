#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>>adj(n+1);
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    vector<int>dist(n+1,1e9);
    vector<int>parent(n+1);
    for(int i=1;i<=n;i++) parent[i] =i;
    q.push({0,1});  //dist , node
    dist[1] = 0;
    while(q.size()>0){
        int wt = q.top().first;
        int node = q.top().second;
        q.pop();
        
        // if(wt > dist[node]) continue; 
        
        for(auto x:adj[node]){
            int adjnode = x.first;
            int adjwt = x.second;
            if(wt +adjwt < dist[adjnode]){
                dist[adjnode] = wt+adjwt;
                parent[adjnode] = node;
                q.push({dist[adjnode],adjnode});
            }
        }
    }
    if(dist[n] ==1e9) return {-1};
    
    vector<int>path;
    int node =n;
    while( node !=1){  //(node != 1) because 1 is source
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    path.push_back(dist[n]);
    reverse(path.begin(),path.end());
    return path;
}
int main(){
    int n =5;
    int m = 6;
    vector<vector<int>>edges = {{1, 2, 2},{2, 5, 5},{2, 3, 4},{1, 4, 1},{4, 3, 3},{3, 5, 1}};
    vector<int>arr = shortestPath(n,m,edges);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<< " ";
    }
}