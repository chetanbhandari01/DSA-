#include<iostream>
using namespace std;
int main(){
    int arr[7]={1,2,3,5,6,4,3};
    int x=4;
    bool flag=false;
    for(int i=0;i<=6;i++){
        if(arr[i]==x){
            flag=true;
        }
    }
    if(flag==true) cout<<"element present";
    else cout<<"not present";
}