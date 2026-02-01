#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int>twoSum(vector<int>&nums,int target){
    int n=nums.size();
    unordered_map<int,int>map;
    vector<int>ans;
    for(int i=0;i<n;i++){
        int rem=target-nums[i];
        if(map.find(rem)!=map.end()){ //its present 
            ans.push_back(map[rem]); // map[rem]=value
            ans.push_back(i);
        }
        else {
            map[nums[i]]=i;
        }
    }
    return ans;
}
int main(){
    vector<int>v={5,7,9,2};
    vector<int>result=(twoSum(v,11));
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}