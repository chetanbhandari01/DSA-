#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
unordered_map<string,bool>mp;
bool solve(const string& a,const string& b){
    if(a.compare(b)==0){
        return true;
    }
    if(a.length()<=1){
        return false;
    }
    string temp = a+" "+b;
    if(mp.find(temp)!=mp.end()){
        return mp[temp];
    }
    bool flag=false;
    int n=a.size();
    for(int i=1;i<=n-1;i++){
        if(((solve(a.substr(0,i),b.substr(n-i,i))) &&(solve(a.substr(i,n-i),b.substr(0,n-i)))) 
        ||(solve(a.substr(0,i),b.substr(0,i))) && (solve(a.substr(i,n-i),b.substr(i,n-i))) ){
            flag=true;
            break;
        }
    }
    return mp[temp]=flag;
}

int main(){
    string a="great";
    string b="grate";
    if(a.size()!=b.size())cout<<"not scrambled";
    else if(a.size()==0 && b.size()==0) cout<<"not scrambled";
    else {
        cout<<solve(a,b);
    }
}