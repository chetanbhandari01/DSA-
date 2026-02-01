#include<iostream>
#include<vector>
using namespace std;
int matrixscore(vector<vector<int>> &grid){
    int rows=grid.size();
    int cols=grid[0].size();
    for(int i=0;i<rows;i++){    //first check in row zero is there hai tu flip karo
        if(grid[i][0]==0){
            for(int j=0;j<cols;j++){      //flipping
                if(grid[i][j]==0) grid[i][j]=1;
                else grid[i][j]=0;
            }
        }
    }
    //flipping column where no.of zero > no.of one than flip
    
    //counting
    for(int j=0;j<cols;j++){
        int no0=0;
        int no1=0;
        for(int i=0;i<rows;i++){
            if(grid[i][j]==0) no0++;
            else no1++;
        }
        if(no0>no1){     //in column zero are more than flip it for maximum score 
            for(int i=0;i<rows;i++){
                if(grid[i][j]==0) grid[i][j]=1;
                else grid[i][j]=0;
            }
        }
    }

    //calculating score
    int sum=0;
    
    for(int i=0;i<rows;i++){
        int x=1;
        for(int j=cols-1;j>=0;j--){
            sum+=grid[i][j]*x;
            x*=2;
        }
    }
    return sum;

}
int main(){
    vector<vector<int>> grid;
    vector<int> v={0,0,1,1};
    vector<int> v1={1,0,1,0};
    vector<int>v2={1,1,0,0};
    grid.push_back(v);
    grid.push_back(v1);
    grid.push_back(v2);
    cout<<matrixscore(grid);
    
}