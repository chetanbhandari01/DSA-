#include<iostream>
#include<vector>
using namespace std;
void reverse(int i,int j,vector<int>&v){
    while(i<=j){
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
    } 
    for(int i=0;i<=v.size()-1;i++){
        cout<<v[i];
    } 
    cout<<endl;
}
int main(){
    vector<int>v;
    int n;
    cout<<"enter a size : ";
    cin>>n;
    for(int i=0;i<=n-1;i++){
        int q;
        cin>>q;
        v.push_back(q);
    } 
    int k=2;
    if(k>n) k=k%n;
    //rotate
    //n=size
    reverse(0,n-k-1,v);
    reverse(n-k,n-1,v);
    reverse(0,n-1,v);
}