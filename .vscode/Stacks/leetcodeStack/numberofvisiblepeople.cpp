//1944 hard
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> canseepeople(vector<int>&arr){
    int n=arr.size();
    vector<int> ans(n,0);
    stack<int> st;
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        int count=0;
        while(st.size()>0 && arr[i]>st.top()){
            st.pop();
            count++;
        }
        if(st.size()!=0) count++;
        ans[i]=count;
        st.push(arr[i]);
    }
    return ans;
}
int main(){
    vector<int>v={12,3,5,3,6,9};
    vector<int> ans=canseepeople(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}