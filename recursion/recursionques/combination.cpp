//leetcode 39 
//written in leetcode
#include<iostream>
#include<vector>
using namespace std;
void combination(vector<vector<int>> &ans,vector<int>& candidates,vector<int >v,int target,int idx ){
    if(target==0){
        ans.push_back(v);
        return ;
    }
    if(target<0) return ;
    for(int i=idx;i<candidates.size();i++){
        v.push_back(candidates[i]);
        combination(ans,candidates,v,target-candidates[i],i);
        v.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int>v;
    combination(ans,candidates,v,target,0);
    return ans;
        
}
int main(){
    
    vector<int>candidates={2,3,6,7};
    int target=7;
    vector<vector<int>>v=combinationSum(candidates,target);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
}
