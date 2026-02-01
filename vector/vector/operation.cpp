#include<iostream>
#include<vector>  
using namespace std;
int main(){
    vector<int> v; // firstly capacity of vector is 0 after push back is 1 then after 2 ..3
    //insertion or input keliye push back use kar
    v.push_back(5);   // 
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    v.pop_back();     //delecting element from back side
    cout<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";

    }
}