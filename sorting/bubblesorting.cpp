#include<iostream>
using namespace std;
int main(){
    int arr[]={5,2,0,2,1,7,6,0,0};
    int n=9;
    // for(int i=0;i<n-1;i++){
    //     //traverse
    //     for(int j=0;j<n-1-i;j++){   //if(n-1) is code run but if we use(n-1-i) than time com is o(n^2/2)
    //         if(arr[j]>arr[j+1]){
    //             int temp=arr[j];
    //             arr[j]=arr[j+1];
    //             arr[j+1]=temp;       
    //         }
    //     }   
    // }
    // //printing 
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }



    //bubble sort optimised
    for(int i=0;i<n-1;i++){
        bool flag =true;
        //traverse
        for(int j=0;j<n-1-i;j++){   //if(n-1) is code run but if we use(n-1-i) than time com is o(n^2/2)
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp; 
                flag =false;      
            }
        }
        if(flag==true){    //swap didn`t happen
            break;
        }   
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}