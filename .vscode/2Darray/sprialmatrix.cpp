#include<iostream>
using namespace std;
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int m=3;
    int n=3;
    int minr=0;
    int maxr=m-1;
    int minc=0;
    int maxc=n-1;
    int totalcount=m*n;  //total element are 3*3 is 9
    //&&count<=totalcount  these is for not for repeation 
    int count =0;
    while(minr<=maxr && minc<=maxc){
        for(int j=minc;j<=maxc &&count<totalcount;j++){    //right
            cout<<arr[minr][j];
            count++;
        }
        minr++;
       
        for(int j=minr ;j<=maxr &&count<totalcount;j++){  //down
            cout<<arr[j][maxc];  
            count++;
        }
        maxc--;
       
        for(int j=maxc;j>=minc &&count<totalcount;j--){  //left
            cout<<arr[maxr][j];
            count++;
        }
        maxr--;
      
        for(int j=maxr ;j>=minr &&count<totalcount;j--){    //up
            cout<<arr[j][minc];
            count++;
        }
        minc++;
        
    }
    
    
}