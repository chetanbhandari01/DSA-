#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minCostPath(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    dist[0][0] = 0;
    q.push({0,{0,0}}); //{diff ,{row,col}}
    
    int dr[]={-1,0,1,0};
    int dc[] = {0,1,0,-1};
    while(q.size()>0){
        int diff = q.top().first;
        int row = q.top().second.first;
        int col = q.top().second.second;
        q.pop();
        if(row ==n-1 && col ==m-1) return diff;
        for(int i=0;i<4;i++){
            int nrow = row+dr[i];
            int ncol = col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                int neweffort = max(abs(mat[nrow][ncol]-mat[row][col]),diff);
                if(neweffort <dist[nrow][ncol]){
                    dist[nrow][ncol] = neweffort;
                    q.push({neweffort,{nrow,ncol}});
                }
            }
        }
    }
    return 0;
}
int main(){
    vector<vector<int>>grid ={{7, 2, 6, 5},{3, 1, 10, 8}};
    cout<<minCostPath(grid);
}