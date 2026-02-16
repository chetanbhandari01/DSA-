#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>>& image,vector<vector<int>>&vis, int sr, int sc, int color,int p){
    vis[sr][sc] =color;
    int n = image.size();
    int m = image[0].size();
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};
    for(int k=0;k<4;k++){
        int newr = sr+dr[k];
        int newc = sc+dc[k];
        if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]!=color  && image[newr][newc]==p){
            dfs(image,vis,newr,newc,color,p);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    //dfs 
    vector<vector<int>>vis = image;
    int p = image[sr][sc];
    dfs(image,vis,sr,sc,color,p);
    return vis;
}
int main() {

    vector<vector<int>> grid = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    vector<vector<int>>ans = floodFill(grid,1,1,2);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
    }

    return 0;
}
