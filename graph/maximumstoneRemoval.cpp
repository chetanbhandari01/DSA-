#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class disjointset{
public:
    vector<int>size,parent;
    disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void UnionBySize(int u,int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

int maxRemove(vector<vector<int>>& stones) {
    int n = stones.size();
    int maxrow = -1;
    int maxcol = -1;
    for(auto x:stones){
        maxrow = max(maxrow,x[0]);
        maxcol = max(maxcol,x[1]);
    }
    disjointset ds(maxrow+maxcol+1);
    unordered_map<int,int>stonesNode;
    for(auto x:stones){
        int noderow = x[0];
        int nodecol = x[1]+maxrow+1;
        ds.UnionBySize(noderow,nodecol);
        stonesNode[noderow] =1;
        stonesNode[nodecol] =1;
    }
    int cnt =0;
    for(auto x:stonesNode){
        if(ds.findUParent(x.first)==x.first){
            cnt++;
        }
    }
    return n-cnt;
}
int main(){
    vector<vector<int>>arr ={{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout<<maxRemove(arr);
}