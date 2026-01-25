#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>m;
    pair<string,int>p1;//insert method 1 
    p1.first="chetan";
    p1.second=1;
    m.insert(p1);
    
    m["dhruvil"]=12;
    m["raghav"]=111;

    cout<<m.size()<<endl;

    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    
    if(m.find("chetan")!=m.end()) cout<<"exists"<<endl;
    else cout<<"does not exist "<<endl;
    
    cout<<m["chetan"];
}