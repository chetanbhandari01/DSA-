//leet code 779
#include<iostream>
#include<vector>
using namespace std;
int Kthgrammar(int n,int k){
    if(n==1) return 0;
    if(k%2==0){   //number flip hota hai   //k/2
        int prevAns=Kthgrammar(n-1,k/2);
        if(prevAns==0) return 1;   //flipping
        else return 0;
    }
    else{  //odd  //same number hotata    //k/2+1
        int prevAns=Kthgrammar(n-1,k/2+1);
        return prevAns ;
    }
}
int main(){
    int n=4;
    int k=7;
    cout<<Kthgrammar(n,k);
}