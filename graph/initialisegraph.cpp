#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cout<<"no.node and no.edges"<<endl;
    cin>>n>>m;
    //this adjacent matrix take to much space n*n
    int adj[n+1][n+1]={0};
    cout<<"enter a node like (1 2)"<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    //this adjacent vector take less space 2 * edges
    vector<int>adjl[n+1];
    cout<<"enter a node like (1 2)"<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }
}