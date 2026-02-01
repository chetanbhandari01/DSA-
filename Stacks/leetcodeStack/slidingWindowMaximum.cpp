#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int>maxSlidingWindow(vector<int>& nums, int k){
    int n=nums.size();
    vector<int>ngi(n);  //next greater index
    ngi[n-1]=n;
    stack<int>st;
    st.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(st.size()>0 && nums[st.top()] <= nums[i]){
            st.pop();
        }
        if(st.size()==0) ngi[i]=n;
        else ngi[i]=st.top();
        st.push(i);
    }
    vector<int> ans;
    int j=0;
    for(int i=0;i<n-k+1;i++){
        if(j<i) j=i;
        int mx=nums[i];
        while(j < i+k){
            mx=nums[j];
            if(ngi[j]>= i+k) break;
            j=ngi[j];
        }
        ans.push_back(mx);
    }
    return ans;
}
int main(){
    vector<int>v={12,3,5,3,6,9};
    vector<int> ans=maxSlidingWindow(v,3);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}