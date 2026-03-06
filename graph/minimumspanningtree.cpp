#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int spanningTree(int V, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>>adj(V);
    int n = edges.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<edges[0].size();j++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    vector<int>vis(V,0);
    //dont store parent because i want only sum of tree
    q.push({0,0});
    int sum =0;
    while(q.size()>0){
        int node = q.top().second;
        int wt = q.top().first;
        q.pop();
        if(vis[node]==1) continue;
        vis[node] =1;
        sum += wt;
        for(auto x:adj[node]){
            int adjNode = x.first;
            int adjwt = x.second;
            if(vis[adjNode]==0){
                q.push({adjwt,adjNode});
            }
        }
    }
    return sum;
}
int main(){
    int v =3;
    vector<vector<int>>edges={{0, 1, 5},{1, 2, 3},{0, 2, 1}};
    cout<<spanningTree(v,edges);
}