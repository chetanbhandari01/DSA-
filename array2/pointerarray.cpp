#include<iostream>
using namespace std;
int main(){
    int arr[]={1,23,4};
    int* ptr=arr;
    cout<<ptr<<endl;
    cout<<ptr[2]<<endl;//we access all element of array using pointer 
    
    //
    for(int i=0;i<=2;i++){
        cout<<*ptr<<" ";
        ptr++;
    }
    ptr=arr;
}