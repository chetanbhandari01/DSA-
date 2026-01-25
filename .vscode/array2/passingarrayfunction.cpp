#include<iostream>
using namespace std;
void display(int a[]){
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
}
int main(){
    int arr[5]={1,23,4,5,6};
    display(arr);
}