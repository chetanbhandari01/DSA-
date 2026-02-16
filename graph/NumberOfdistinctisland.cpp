#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
void bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j,vector<pair<int,int>>&vec){
    int n = grid.size();
    int m = grid[0].size();
    vis[i][j] =1;
    queue<pair<int,int>>q;
    int base1 = i;
    int base2 = j;
    q.push({i,j});
    vec.push_back({i-base1,j-base2});
    int dr[4]={-1,0,1,0};
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
                vec.push_back({newr-base1,newc-base2});
                vis[newr][newc]=1;
            }
        }
    }
}
int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>>vis(n,vector<int>(m,0));
    set<vector<pair<int,int>>>st;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && vis[i][j]==0){
                vector<pair<int,int>>vec;
                bfs(grid,vis,i,j,vec);
                st.insert(vec);
            }
        }
    }
    return st.size();
}
int main() {

    vector<vector<int>> grid = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    int result = countDistinctIslands(grid);

    cout << result << endl;


    return 0;
}