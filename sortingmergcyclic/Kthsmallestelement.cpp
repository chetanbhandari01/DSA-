#include<iostream>
using namespace std;
int partition(int arr[],int si,int ei){
    int pivotele=arr[(si+ei)/2];
    int count=0;
    for(int i=si;i<=ei;i++){
        if(i==(si+ei)/2) continue;
        if(pivotele>=arr[i]) count++;
    }
    int pivotidx=count+si;
    swap(arr[(si+ei)/2],arr[pivotidx]);
    int i=si;
    int j=ei;
    while(i<pivotidx && j>pivotidx){
        if(arr[i]<pivotele) i++;
        if(arr[j]>pivotele) j--;
        else if(arr[i]>pivotele && arr[j]<=pivotele){
            swap(arr[i],arr[j]);
            j--;
            i++;
        }
    }
    return pivotidx;
}
int quicksort(int arr[],int si,int ei,int k){
   
    int pivotidx=partition(arr,si,ei);
    if(pivotidx+1==k) return arr[pivotidx];
    else if(pivotidx+1<k) return quicksort(arr,pivotidx+1,ei,k);
    else return quicksort(arr,si,pivotidx-1,k);
}
int main(){
    int arr[]={5,1,8,2,7,6,3,4};
    int k=2;
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<quicksort(arr,0,n-1,n-k);
}