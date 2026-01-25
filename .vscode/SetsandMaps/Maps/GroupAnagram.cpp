#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<string>>groupAnagram(vector<string>str){
    int n=str.size();
    vector<vector<string>>ans;
    unordered_map<string ,vector<string>>mp;
    for(int i=0;i<n;i++){
        string lexo=str[i];
        sort(lexo.begin(),lexo.end());
        if(mp.find(lexo)==mp.end()){
            vector<string>v;
            v.push_back(str[i]);
            mp[lexo]=v;
        }
        else{
            mp[lexo].push_back(str[i]);
        }
    }
    for(auto x:mp){
        vector<string>s=x.second;
        ans.push_back(s);
    }
    return ans;
}
int main(){
    vector<string>s={"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans=groupAnagram(s);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
    }
}