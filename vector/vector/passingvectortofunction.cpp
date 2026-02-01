#include<iostream>
#include<vector>
using namespace std; 
void change(vector<int> &a){    //using function use & operator then only change happen
    a[0]=100;
}
int main(){
    vector<int>v;
    v.push_back(9);
    v.push_back(5);
    v.push_back(3);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    change(v);
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}