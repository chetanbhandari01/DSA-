//find the last occurrence of x in the array and print index of x
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    int x=2;
    v.push_back(5);
    v.push_back(4);
    v.push_back(6);
    v.push_back(2);
    v.push_back(4);
    for(int i=v.size()-1;i>=0;i--){
        if(x==v[i]){
            cout<<i;
            break;
        }
    }
}