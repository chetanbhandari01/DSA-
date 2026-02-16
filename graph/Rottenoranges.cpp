#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int,int>,int>>q;
    vector<vector<int>>vis(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j] =2;
            }
        }
    }

    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    int tm =0;
    while(q.size()>0){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        tm =max(tm,t);
        for(int d=0;d<4;d++){
            int newr = r+dr[d];
            int newc = c+dc[d];

            if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==0 && grid[newr][newc]==1){
                q.push({{newr,newc},t+1});
                vis[newr][newc] = 2;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0 && grid[i][j]==1 ){
                return -1;
            }
        }
    }
    return tm;
}
int main() {

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int result = orangesRotting(grid);

    cout << "Minimum time to rot all oranges: " << result << endl;

    return 0;
}
