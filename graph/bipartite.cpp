#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool check(int node ,int col,vector<vector<int>>& graph,vector<int>&color){
    color[node] = col;
    for(auto x: graph[node]){
        if(color[x]==-1){
            if(check(x,!col,graph,color)==false){
                return false;
            }
        }
        else if(color[x]==color[node]){
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int>color(n,-1);
    for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(check(i,0,graph,color)==false){
                return false;
            }
        }
    }
    return true;
}
int main() {

    vector<vector<int>> grid = {
        {2,3,1},
        {4,5,0},
        {0,1,1}
    };

    cout<<isBipartite(grid);

    return 0;
}
