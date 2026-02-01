#include<iostream>
using namespace std;
void startriangle(int a){
    for(int i=1;i<=a;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return ;
}
int main(){
    int a;
    for(int i=1;i<=3;i++){
        cout<<"enter number : ";
        cin>>a;
        startriangle(a);
    }
    
}