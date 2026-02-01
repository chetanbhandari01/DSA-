#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v;
    v.push_back(40);
    v.push_back(5);
    v.push_back(8);
    v.push_back(2);

    cout<<v.at(2)<<endl;  // same as v[2]
    v.at(3)=60;
    cout<<v.at(3)<<endl;

    //sort
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}