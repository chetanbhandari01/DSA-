#include<iostream>
#include<vector>
using namespace std;
void dfsG(int node,vector<vector<int>>&adj,vector<int>&vis){
    vis[node] = 1;
    for(auto x: adj[node]){
        if(vis[x] == 0){
            dfsG(x,adj,vis);
        }
    }   
}
int findCircleNum(vector<vector<int>>& mat) {
    int n = mat.size();
    //write adjaceny list 
    vector<vector<int>>adj(n); 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int>vis(n,0);
    
    int count=0;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            count++;
            dfsG(i,adj,vis);
        }
    }
    return count;
}
int main() {

    vector<vector<int>> grid = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    int result = findCircleNum(grid);

    cout << result << endl;

    return 0;
}
