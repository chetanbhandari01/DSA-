#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class disjointset{
    vector<int>rank,parent;
public:
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] =i;
        }
    }
    int findURank(int node){
        if(node ==parent[node]){
            return node;
        }
        return parent[node] = findURank(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u = findURank(u);
        int ulp_v = findURank(v);
        if(ulp_u == ulp_v) return ;
        if(rank[ulp_u] < rank[ulp_v]){  //u ka parent v hai 
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int spanningTree(int V, vector<vector<int>>& edges) {
    vector<pair<int,pair<int,int>>>adj;
    for(int i=0;i<edges.size();i++){  //TC = O(M)  m=no.of edges
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        
        adj.push_back({wt,{u,v}});
    }
    sort(adj.begin(),adj.end()); //TC = Mlog(M)
    disjointset ds(V);
    int mst = 0;
    for(auto it : adj){   //TC = M * 4 * alpha
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findURank(u) != ds.findURank(v)){
            mst += wt;
            ds.unionByRank(u,v);
        }
    }
    return mst;
}
int main(){
    int v= 3;
    vector<vector<int>>arr ={{0 ,1 ,5},{1,2,3},{0,2,1}};
    cout<<spanningTree(v,arr);
}