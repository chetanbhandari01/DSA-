#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0]==1) return -1;

    int n = grid.size();
    if(n-1 == 0 ) return 1;
    queue<pair<int,pair<int,int>>>q;
    vector<vector<int>>dist(n,vector<int>(n,1e9));
    dist[0][0] = 1;
    q.push({1,{0,0}});
    int dr[] = {-1,-1,0,1,1,1,0,-1};
    int dc[] = {0,1,1,1,0,-1,-1,-1};
    while(q.size()>0){
        int dis = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        for(int i=0;i<8;i++){
            int rnew = row+dr[i];
            int cnew = col+dc[i];

            if(rnew>=0 && rnew<n && cnew>=0 && cnew<n && grid[rnew][cnew]==0 && dis+1 < dist[rnew][cnew]){
                dist[rnew][cnew] = dis+1;
                if(n-1==rnew && n-1==cnew){
                    return dis+1;
                }
                q.push({dis+1,{rnew,cnew}});
            }
        }
    }
    return -1;
}
int main(){
    vector<vector<int>>grid ={{0,0,0},{1,1,0},{1,1,0}};
    cout<<shortestPathBinaryMatrix(grid);
}