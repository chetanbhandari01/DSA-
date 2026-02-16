#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int row,int col,vector<vector<int>>&visited,vector<vector<char>>&grid){
    int n = grid.size();
    int m = grid[0].size();
    visited[row][col] = 1;
    queue<pair<int,int>>q;
    q.push({row,col});

    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        
        //traverse in neighbour to mark them if it is land
        // 4 direction  (up down left,right)  up-> (row-1,col) down=(row+1,col) left =(row,col-1) right = (row,col+1)
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};
        for(int d =0;d<4;d++){
            int nrow = r + dr[d]; //neigbour row
            int ncol = c + dc[d];

            if(nrow >=0 && nrow<n && ncol >=0 && ncol<m && grid[nrow][ncol] =='1' && visited[nrow][ncol]==0){
                visited[nrow][ncol] =1; 
                q.push({nrow,ncol});
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>visited(n,vector<int>(m,0));
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==0 && grid[i][j]=='1'){ 
                count++;
                bfs(i,j,visited,grid);
            }
        }
    }
    return count;
}
int main() {

    vector<vector<char>> grid = {
        {'1','1','0'},
        {'1','1','0'},
        {'0','0','1'}
    };

    int result = numIslands(grid);

    cout << result << endl;

    return 0;
}