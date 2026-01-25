#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int helper(vector<int>&v){
    int n= v.size();
    int count=0;
    int max_so_far=v[0];
    for (int i = 1; i < n; i++) {
        if (v[i] < max_so_far) {
            count++;    //3 1 4 5 2
        } else {
            max_so_far = v[i];
        }
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>v;
        for(int i=0;i<n;i++){
            int m;
            cin>>m;
            v.push_back(m);
        }
        cout<<helper(v)<<endl;
    }
    
}