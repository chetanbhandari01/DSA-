#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v={1,2,3};
    int n=v.size();
    int i=v.size()-2;
    while(i>=0 && v[i]>=v[i+1]){
        i--;
    }
    if(i>=0){
        int j=n-1;
        while(v[j]>v[i]){
           
        }
    }
}