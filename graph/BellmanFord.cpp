#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int>dist(V,1e8);
    dist[src] =0;
    for(int i=0;i<V-1;i++){
        for(auto x: edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            if(dist[u]!=1e8 && dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
            }
        }
    }
    // if negative cycle is detect return -1 
    for(auto x:edges){
        int u = x[0];
        int v = x[1];
        int wt = x[2];
        if(dist[u] !=1e8 && dist[u] +wt <dist[v]){
            return {-1};
        }
    }
    return dist;
}
int main(){
    int v =5;
    vector<vector<int>>arr={{1, 3, 2},{4, 3, -1},{2, 4, 1},{1, 2, 1},{0, 1, 5}};
    int src =0;
    vector<int>ans = bellmanFord(v,arr,src);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}