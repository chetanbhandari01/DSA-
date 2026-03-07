#include<iostream>
#include<set>
#include<vector>
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
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void unionBysize(int u,int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};
int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    disjointset ds(n*n);
    //step 1
    for(int row =0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col] ==0)continue;
            int dr[4] = {-1,0,1,0};
            int dc[4] = {0,-1,0,1};
            for(int i=0;i<4;i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];
                if(nrow<n && nrow>=0 && ncol<n && ncol>=0 && grid[nrow][ncol]==1){
                    int node = row*n+col;
                    int adjnode = nrow*n +ncol;
                    ds.unionBysize(node,adjnode);
                }
            }
        }
    }
    // step 2
    int mx =0;
    for(int row =0;row<n;row++){
        for(int col=0;col<n;col++){
            if(grid[row][col] ==1)continue;
            int dr[4] = {-1,0,1,0};
            int dc[4] = {0,-1,0,1};
            set<int>components;
            for(int i=0;i<4;i++){
                int nrow = row+dr[i];
                int ncol = col+dc[i];
                if(nrow<n && nrow>=0 && ncol<n && ncol>=0 && grid[nrow][ncol]==1){
                    components.insert(ds.findUParent(nrow*n+ncol));
                }
            }
            int sizetotal =1; //khud ki size 1 hogi
            for(auto x:components){
                sizetotal += ds.size[x];
            }
            mx = max(mx,sizetotal);
        }
    }
    for(int cell =0;cell<n*n;cell++){
        mx = max(mx,ds.size[ds.findUParent(cell)]);
    }
    return mx;
}
int main(){
    vector<vector<int>>grid = {{1,1},{1,0}};
    cout<<largestIsland(grid);
}