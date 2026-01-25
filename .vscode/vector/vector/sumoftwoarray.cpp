//find the doublet in the array whose sum is equal to the given value x.
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);
    v.push_back(5);
    v.push_back(2);
    int sum=7;
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<=v.size()-1;j++){
            if(sum==v[i]+v[j]){
                cout<<i<<" "<<j<<endl;
            }
        }
    }
}