//sum of two number using dereference
#include<iostream>
using namespace std;
int main(){
    int x;
    int y;
    int *p1=&x;
    int *p2=&y;
    cout<<"enter number : ";
    cin>>*p1;   //*p1 you can use x also
    cout<<"enter number : ";
    cin>>*p2;   
    cout<<*p1 + *p2;     //x y also use 
   
}