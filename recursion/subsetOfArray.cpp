#include<iostream>
#include<vector>
using namespace std;
void printsubset(int arr[],int idx,int n,vector<int>ans){
    if(idx==n){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return;
    }
    printsubset(arr,idx+1,n,ans);
    ans.push_back(arr[idx]);
    printsubset(arr,idx+1,n,ans);

}
int main(){
    int arr[]={1,2,3};
    vector<int>v;
    int n=sizeof(arr)/sizeof(arr[0]);
    printsubset(arr,0,n,v);
}



