#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dist(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({{i,j},0});
                vis[i][j]=1;
            }
        }
    }

    int dr[4] ={-1,0,1,0};
    int dc[4] ={0,1,0,-1};

    while(q.size()>0){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int d = q.front().second;
        dist[r][c] = d;
        q.pop();
        for(int k=0;k<4;k++){
            int newr = r+dr[k];
            int newc = c+dc[k];

            if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==0 ){
                q.push({{newr,newc},d+1});
                vis[newr][newc] =1;
            }
        }
    }
    return dist;
}
int main() {

    vector<vector<int>> grid = {
        {1,1,1},
        {1,1,0},
        {0,1,1}
    };

    vector<vector<int>>ans = updateMatrix(grid);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }
    }

    return 0;
}
