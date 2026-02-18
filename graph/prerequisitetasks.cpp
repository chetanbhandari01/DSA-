#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
    vector<vector<int>>adj(N);
    for(auto x:prerequisites){
        int u = x.first;
        int v = x.second;
        adj[u].push_back(v); 
        //to know 1 we will know to 0 means 
    }
    //indregee matrix means incoming edges
    vector<int>indegree(N,0);
    for(int i=0;i<N;i++){
        for(auto x:adj[i]){
            indegree[x]++;
        }
    }
    
    //
    queue<int>q;
    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    
    //
    vector<int>topo;
    while(q.size()>0){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto x: adj[node]){
            indegree[x]--;
            if(indegree[x]==0){
                q.push(x);
            }
        }
    }
    
    //
    if(topo.size()==N) return true;
    return false;
}
int main() {
    int N, P;

    cout << "Enter number of courses (N): ";
    cin >> N;

    cout << "Enter number of prerequisites (P): ";
    cin >> P;

    vector<pair<int, int>> prerequisites;

    cout << "Enter prerequisites (u v) meaning v -> u:\n";
    for(int i = 0; i < P; i++) {
        int u, v;
        cin >> u >> v;
        prerequisites.push_back({u, v});
    }

    if(isPossible(N, P, prerequisites)) {
        cout << "It is possible to finish all courses.\n";
    } else {
        cout << "It is NOT possible (cycle detected).\n";
    }

    return 0;
}