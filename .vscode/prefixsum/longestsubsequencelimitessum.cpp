//leetcode 2389
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n=nums.size();
    int m=queries.size();
    vector<int >ans(m);
    //sorting nums
    sort(nums.begin(),nums.end());
    //make nums prefix sum
    for(int i=1;i<n;i++){
        nums[i] =nums[i]+ nums[i-1];
    }
    for(int i=0;i<m;i++){
        int maxlen=0;
        int lo=0;
        int hi=n-1;
        while(lo<=hi){   //binary for good time complexity
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>queries[i]) hi=mid-1;
            else {
                maxlen=mid+1;
                lo=mid+1;
            }
        }
        ans[i]=maxlen;
    }
    return ans;
}
int main(){
    vector<int>v1 = {4,5,2,1};
    vector<int>v2={3,10,21};
    vector<int>v=answerQueries(v1,v2);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}