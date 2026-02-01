//hierarchy 
#include<iostream>
using namespace std;
int main(){
    int p=5 ,q=10;
    p += q -= p;  //in assing case go right to left
    cout<<p<<" "<<q<<endl;

}