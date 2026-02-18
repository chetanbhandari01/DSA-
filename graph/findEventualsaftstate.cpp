#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    int m = graph[0].size();
    //make adjacency matrix
    vector<vector<int>>adj(n);
    for(int i=0;i<n;i++){
        for(auto x:graph[i]){
            adj[x].push_back(i);    //reverse in topological sort 
        }
    }
    //
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto x: adj[i]){
            indegree[x]++;
        }
    }
    //
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i] ==0){
            q.push(i);
        }
    }
    //
    vector<int>topo;
    while(q.size()>0){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto x:adj[node]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
    sort(topo.begin(),topo.end());
    return topo;
}
int main() {

    vector<vector<int>> grid = {
        {1,2},
        {2,3},
        {5},
        {0}
    };

    vector<int>ans = eventualSafeNodes(grid);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
