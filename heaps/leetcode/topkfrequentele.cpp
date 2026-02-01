#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int>topkfreqele(vector<int>& nums, int k){
    int n=nums.size();
        unordered_map<int,int>mp;//element ko map dala
        for(int x:nums){
            mp[x]++;    //ele,freq
        }
        //heap mein dalo (freq,ele)
        //min heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto x:mp){
            int freq=x.second;
            int ele=x.first;
            pq.push({freq,ele});
            if(pq.size() >k) pq.pop();
        }
        vector<int>ans;
        while(pq.size()>0){
            int ele = pq.top().second;
            ans.push_back(ele);
            pq.pop();
        }
        return ans;
    }

int main(){
    vector<int>nums={1,1,3,3,2,2,1,2};
    vector<int>ans=topkfreqele(nums,2);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}