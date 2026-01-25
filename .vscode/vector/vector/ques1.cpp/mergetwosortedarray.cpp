#include<iostream>
#include<vector>
using namespace std;
int mergesort(vector<int>&v1,vector<int>&v2,vector<int>&v3){
    int i=0;
    int j=0;
    int k=0;
    int n=v1.size();
    int m=v2.size();
    while(i<=n-1 && j<=m-1){
        if(v1[i]<v2[j]){
            v3[k]=v1[i];
            k++;
            i++;
        }
        else if(v1[i]>v2[j]){
            v3[k]=v2[j];
            j++;
            k++;
        }   
    }
    //for remainging element
    if(i==n){  //v1 ke saare element utha chucke hai
        while(j<=m-1){  //v2 ke liye
            v3[k]=v2[j];
            j++;
            k++;
        }
    }
    if(j==m){  //v2 ke saare element utha chucka hai
        while(i<=n-1){
            v3[k]=v1[i];
            i++;
            k++;
        }
    }
    return v3[k];
}
int main(){
    vector<int>v1(4);
    v1[0]=1;
    v1[1]=3;
    v1[2]=6;
    v1[3]=7;
     
    vector<int>v2(4);
    v2[0]=2;
    v2[1]=4;
    v2[2]=5;
    v2[3]=8;
  
    int n=v1.size();
    int m=v2.size();
    vector<int>v3(m+n);
    mergesort(v1,v2,v3);
    for(int i=0;i<n+m;i++){
        cout<<v3[i]<<" ";
    }
}