#include<iostream>
#include<vector>
using namespace std;
int calAverage(vector<int>&arr,int maxA){
    int n=arr.size();
    //int k=2;
    for(int k=2;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j=i;
            int sum=0;
            while(j<i+k){
                sum+=arr[j];
                j++;
            }
            sum/=k;
            maxA=max(sum,maxA);
        }
    }
    return maxA;
}
int main(){
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int>arr;
        int maxA=INT_MIN;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            maxA=max(a,maxA);
            arr.push_back(a);
        }
        int ans=calAverage(arr,maxA);
        cout<<ans<<endl;
    }
}