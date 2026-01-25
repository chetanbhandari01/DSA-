#include<iostream>
#include<vector>  
using namespace std;
int main(){
    vector<int> v; // firstly capacity of vector is 0 after push back is 1 then after 2 ..3
    //insertion or input keliye push back use kar
    v.push_back(5);
    cout<<v.capacity()<<endl;   //capacity is multiply of 2 |5|6|7|7|7| 
    v.push_back(6);
    cout<<v.capacity()<<endl;
    v.push_back(7);
    cout<<v.capacity()<<endl;
    v.push_back(7);
    cout<<v.capacity()<<endl;
    v.push_back(7);
    cout<<v.capacity()<<endl;
    cout<<endl;
    //
    //size of vector
    cout<<v.size()<<endl;  //vector give size of vector direct using function

    //printing vector
    cout<<v[0]<<" ";
    cout<<v[1]<<" ";
    cout<<v[2]<<" ";
    cout<<v[2]<<" ";
    
}