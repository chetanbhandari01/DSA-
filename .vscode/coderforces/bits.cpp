#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int X=0;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        if("--X"==str){
            --X;
        }
        else if("++X"==str){
            ++X;
        }
        else if("X++"==str){
            X++;
        }
        else {
            X--;
        }
    }
    cout<<X;
}
