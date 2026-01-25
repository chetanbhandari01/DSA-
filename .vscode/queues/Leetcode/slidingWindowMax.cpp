#include<iostream>
#include<deque>
#include<vector>
using namespace std;
vector<int>maxInWindow(vector<int>&arr ,int k){
    int n=arr.size();
    deque<int>dq;
    vector<int>ans;
    for(int i=0;i<n;i++){
        while(dq.size()>0 && arr[i] > arr[dq.back()]) dq.pop_back(); 
        dq.push_back(i);
        int j=i-k+1;
        while(dq.front()<j) dq.pop_front();
        if(i>=k-1) ans.push_back(arr[dq.front()]);
    }
    return ans;
}
int main(){
    vector<int> arr={7,2,3,9,4,1};
    int k=2;
    vector<int>ans={maxInWindow(arr,k)};
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }

}