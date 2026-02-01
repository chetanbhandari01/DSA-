#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[]={0,1,3,5,7,5};
    int n=6;
    int lo=0;
    int hi=n-1;
    int ans=-1;
    while(lo<=hi){
        int mid=(hi+lo)/2;
        if(arr[mid]==mid) {
            lo=mid+1;       //means idx and number are same check forward
        }
        else{
            ans=mid;
            hi=mid-1;
        }

    }
    cout<<ans;
}