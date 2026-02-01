#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void permutation(vector<int>&v){
    int n=v.size();
    int idx=-1;
    for(int i=n-2;i<=0;i--){ //finding index
        if(v[i]<v[i+1]){
            idx=i;
            break;
        }
    }
    if(idx==-1){   //if array is already greatest
        reverse(v.begin(),v.end());
        return;
    }
    //2.sorting /reverse after index 
    reverse(v.begin()+idx+1,v.end());
    //3.finding the just greater element than idx
    int j=-1; //greater number
    for(int i=idx+1;i<n;i++){
        if(v[i]>v[idx]){
            j=i;
            break;
        }
    }
    //4.swapping idx and j
    int temp=v[idx];
    v[idx]= v[j];
    v[j]=temp;

}
int main(){
    vector<int>v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    permutation(v);
    int n=v.size();
    for(int i=0;i<=n-1;i++){
        cout<<v[i]<<" ";
    }
}