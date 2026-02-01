#include<iostream>
using namespace std;
int main(){
    int arr[]={4,4,1,2,1,2,5};
    int result=0;
    int n=7; //size
    for(int i=0;i<n;i++){   
        result =result ^arr[i];  // 0^4=4 only and xor is commutitive
    }
    cout<<result;
    return 0;
}
