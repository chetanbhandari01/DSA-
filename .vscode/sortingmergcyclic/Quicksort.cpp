#include<iostream>
using namespace std;
int partition(int arr[],int startingIdx,int endingIdx){
    int pivotele=arr[(startingIdx+endingIdx)/2];  //pivot element  // or worse case nahi ahe
    int count=0;
    for(int i=startingIdx;i<=endingIdx;i++){
        if(i==(startingIdx+endingIdx)/2) continue;  //5==5 continue karo
        if(arr[i]<=pivotele) count++;
    }
    int pivotIdx=count+startingIdx;
    swap(arr[(startingIdx+endingIdx)/2],arr[pivotIdx]);
    int i=startingIdx;
    int j=endingIdx;
    while(i<pivotIdx && j>pivotIdx){
        if(arr[i]<=pivotele) i++;
        if(arr[j]>pivotele) j--;
        else if(arr[i]>pivotele && arr[j]<=pivotele){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;
}
void quicksort(int arr[],int startingIdx,int endindIdx){
    if(startingIdx>=endindIdx) return ;       //base case
    //5,1,8,2,7,6,3,4
    int pivotIdx=partition(arr,startingIdx,endindIdx);
    //4,1,3,2,5,7,8,6
    quicksort(arr,startingIdx,pivotIdx-1);
    quicksort(arr,pivotIdx+1,endindIdx);

}
int main(){
    int arr[]={5,1,8,2,7,6,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}