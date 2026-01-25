#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&v1,vector<int>&v2,vector<int>&res ){
    int i=0;
    int j=0;
    int k=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<=v2[j]){
            res[k]=v1[i];
            i++;
            k++;
        }
        else if(v1[i]>v2[j]){
            res[k]=v2[j];
            j++;
            k++;
        }
    }
    if(i==v1.size()){
        while(j<v2.size()){
            res[k]=v2[j];
            k++;
            j++;
        }
    }
    if(j==v2.size()){
        while(i<v1.size()){
            res[k]=v1[i];
            i++;
            k++;
        }
    } 
}
void mergeSort(vector<int>&v){
    int n=v.size();
    if(n==1) return ;
    int n1=n/2;
    int n2=n-n/2;
    vector<int > a(n1),b(n2);
    //copyig vector to a1,b1
    for(int i=0;i<n1;i++){
        a[i]=v[i];
    }
    for(int i=0;i<n2;i++){
        b[i]=v[i+n1];
    }
    //magic a ka recursion
    mergeSort(a);
    mergeSort(b);
    //merge two vector a,b
    merge(a,b,v); 
    a.clear();  //FOR SAVING space complexity 
    b.clear();
}
int main(){
    int arr[]={5,1,3,0,4,9,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n);   //v vector me arr store hota he
   
    mergeSort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}