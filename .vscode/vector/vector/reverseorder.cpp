//program to copy the content of one array into another in the reverse order
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>v1;
    int n;
    cout<<"enter size : ";
    cin>>n;
    for(int k=0;k<n;k++){
        int q;
        cin>>q;
        v1.push_back(q);
    }
     
    //reverse order
    vector<int>v2(v1.size());
    for(int i=0;i<v1.size();i++){
        //i + j=size -1
        int j=v1.size()-1-i;
        v2[i]=v1[j];
        cout<<v2[i]<<" ";
    }

}