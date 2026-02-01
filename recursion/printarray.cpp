#include<iostream>
#include<vector>
using namespace std;
void display(int arr[],int m,int idx){
    if(m==idx) return ;
    cout<<arr[idx]<<" ";
    display(arr,m,idx+1);
}
void displayy(vector<int>&v,int n,int idx){
    if(n==idx) return ;
    cout<<v[idx]<<" ";
    displayy(v,n,idx+1);
}
int main(){
    int arr[]={1,2,3,5,4,6};
    int m=sizeof(arr)/sizeof(arr[0]);
    display(arr,m,0);
    cout<<endl;
    vector<int>v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    int n=v.size();
    displayy(v,n,0);
    
}