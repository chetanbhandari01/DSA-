#include<iostream>
#include<vector>
using namespace std;
bool increasing(vector<int>&arr,int m){
    for(int i=0;i<m-1;i++){
        if(arr[i]>=arr[i+1]) return false;
    }
    return true;
}
void Subarray(int n,int m,vector<int>&arr){
    
    if(increasing(arr,m)==true){
        cout<<n-arr[m-1]+1;
    }
    else cout<<1;
    
}
int main(){
    int t; //test case
    cin>>t;
    for(int i=0;i<t;i++){
        int n,m;
        cin>>n ;
        cin>>m;
        vector<int>arr(m);
        for(int i=0;i<m;i++){
            int q;
            cin>>q;
            arr[i]=q;
        }
        Subarray(n,m,arr);
        cout<<endl;
    }
}