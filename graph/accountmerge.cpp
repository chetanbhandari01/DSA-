#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class disjointset{
public: 
    vector<int>rank,parent;
    disjointset(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] =i;
        }
    }
    int findURank(int node){
        if(node ==parent[node]){
            return node;
        }
        return parent[node] = findURank(parent[node]);
    }
    void unionByRank(int u,int v){
        int ult_u = findURank(u);
        int ult_v = findURank(v);
        if(ult_u == ult_v) return ;
        else if(rank[ult_u] < rank[ult_v]){
            parent[ult_u] = ult_v;
        }
        else if(rank[ult_v] <rank[ult_u]) {
            parent[ult_v] = ult_u;
        }
        else{
            parent[ult_v] = ult_u;
            rank[ult_u]++;
        }
    }
};
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    disjointset ds(n);
    unordered_map<string,int>mailNode;
    for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            string mail = accounts[i][j]; 
            if(mailNode.find(mail) == mailNode.end()){
                mailNode[mail] =i;
            }
            else {
                ds.unionByRank(i,mailNode[mail]);
            }
        }
    }
    vector<string>mergemail[n];
    for(auto x:mailNode){
        string mail = x.first;
        int node = ds.findURank(x.second);
        mergemail[node].push_back(mail);
    }
    vector<vector<string>>ans;
    for(int i=0;i<n;i++){
        if(mergemail[i].size()==0) continue;
        sort(mergemail[i].begin(),mergemail[i].end());
        vector<string>temp;
        temp.push_back(accounts[i][0]);
        for(auto x:mergemail[i]){
            temp.push_back(x);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    vector<vector<string>>accounts ={
        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };
    vector<vector<string>> ans = accountsMerge(accounts);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<endl;
        }
    }
}