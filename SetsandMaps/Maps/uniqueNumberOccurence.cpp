#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
bool uniqueOccurence(vector<int>&arr){
    int n=arr.size();
    unordered_map<int,int>map;
    for(int i=0;i<n;i++){
        map[arr[i]]++;
    }
    unordered_set<int>s;
    for(auto x:map){
        s.insert(x.second);
    }
    if(s.size()!=map.size()) return false;
    return true;
}
int main(){
    vector<int>v = {1,4,2,2,2,1};
    cout<<uniqueOccurence(v);
}