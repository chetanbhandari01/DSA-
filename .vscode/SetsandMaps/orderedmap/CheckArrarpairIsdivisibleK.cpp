#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
bool canArrange(vector<int>arr,int k){
    int n=arr.size();
    unordered_map<int ,int>m;
    for(int i=0;i<n;i++){
        m[((arr[i]%k)+k)%k]++;
    }
    //zero case
    if(m.find(0)!=m.end()){
        if(m[0]%2!=0) return false;
        m.erase(0);
    }
    for(auto x:m){
        int ele =x.first;
        int rem=k-ele;
        if(m.find(rem)==m.end()) return false;
        if(m[rem]!=m[ele]) return false;
        
    }
    return true;
}
int main(){
    vector<int>v={-1,1,-2,2,-3,3,-4,4};
    cout<<canArrange(v,10);
}