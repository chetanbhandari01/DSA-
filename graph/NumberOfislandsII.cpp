#include<iostream>
#include<vector>
using namespace std;
class disjointset{
public:
    vector<int>size,parent;
    disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] =i;
        }
    }
    int findUParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void unionByrank(int u,int v){
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
vector<int>numofisland(int n,int m,vector<vector<int>>&arr){
    disjointset ds(n*m);
    vector<vector<int>>vis(n,vector<int>(m,0));
    int cnt =0;
    vector<int>ans;
    for(auto x: arr){
        int row = x[0];
        int col = x[1];
        if(vis[row][col] ==1){
            ans.push_back(cnt);
            continue;
        }
        vis[row][col] =1;
        cnt++;

        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow = row+dr[i];
            int ncol = col+dc[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m ){
                if(vis[nrow][ncol] ==1){   //land is there
                    int nodeNo = row*m + col;
                    int adjNodeNo = nrow*m+ncol;
                    if(ds.findUParent(nodeNo) != ds.findUParent(adjNodeNo)){
                        cnt--;
                        ds.unionByrank(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        ans.push_back(cnt);
    }
    return ans;
}
int main(){
    int n = 4;
    int m=5;
    vector<vector<int>>arr={{1,1},{0,1},{3,3},{3,4}};
    vector<int>ans = numofisland(n,m,arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}