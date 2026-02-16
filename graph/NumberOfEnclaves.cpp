#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m =grid[0].size();

    vector<vector<int>>vis(n,vector<int>(m,0));
    queue<pair<int,int>>q;

    for(int i=0;i<n;i++){
        if(grid[i][0]==1){
            vis[i][0] =1;
            q.push({i,0});
        }
        if(grid[i][m-1]==1){
            vis[i][m-1]=1;
            q.push({i,m-1});
        }
    }
    for(int i=0;i<m;i++){
        if(grid[0][i]==1){
            vis[0][i]=1;
            q.push({0,i});
        }
        if(grid[n-1][i]==1){
            vis[n-1][i]=1;
            q.push({n-1,i});
        }
    }

    //
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,1,0,-1};

    while(q.size()>0){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int d=0;d<4;d++){
            int newr = r+dr[d];
            int newc = c+dc[d];

            if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==0 && grid[newr][newc]==1){
                q.push({newr,newc});
                vis[newr][newc]=1;
            }
        }
    }

    //count
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && grid[i][j]==1){
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {

    vector<vector<int>> grid = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    int result = numEnclaves(grid);

    cout << result << endl;

    return 0;
}