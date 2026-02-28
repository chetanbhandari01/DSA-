#include<iostream>
#include<vector>
using namespace std;
class disjoint_set{
    vector<int>rank,parent;
public: 
    disjoint_set(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] =i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);  //storing means comparsions tree
    }
    void unoinByparent(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int main(){
    disjoint_set ds(7);
    ds.unoinByparent(1,2);
    ds.unoinByparent(2,3);
    ds.unoinByparent(4,5);
    ds.unoinByparent(6,7);
    ds.unoinByparent(5,6);
    //check for 3 and 7 parent 
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"same parent"<<endl;
    }
    else {
        cout<<"not same"<<endl;
    }
    ds.unoinByparent(3,7);
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"same parent"<<endl;
    }
    else {
        cout<<"not same"<<endl;
    }
}