#include<iostream>
#include<string>
using namespace std;
// maximum in number in string (leetcode)
int main(){
    string arr[]={"0123","0023","012394","9443"};
    int max=stoi(arr[0]);
    string maxS=arr[0];
    for(int i=1;i<=3;i++){
        int x=stoi(arr[i]);
        if(x>max){
            max=x;
            maxS=arr[i];
        }

    }
    cout<<max<<" = "<<maxS;
}