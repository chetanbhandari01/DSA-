#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int arr[5]={14,3,3,1,15};
    int n=5;
    vector<int>v(n,0);    //0 means not visited array
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int x=0;
    for(int i=0;i<n;i++){
        int min=INT_MAX;
        int mindx=-1;
        for(int j=0;j<n;j++){
            if( v[j]==1) continue;
            else{   //v[j]==0
                if(min>arr[j]){
                    min=arr[j];
                    mindx=j;
                }
            }
        }
        arr[mindx]=x;
        v[mindx]=1;
        x++;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}