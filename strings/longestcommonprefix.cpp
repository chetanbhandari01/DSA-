#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string longestcommonprefix(vector<string> &str){
    int n=str.size();
    if(n==1) return str[0];
    sort(str.begin(),str.end());
    //
    string first=str[0];
    string last =str[n-1];
    string newS="";          //new string made store 
    for(int i=0;i<min(first.size(),last.size());i++){
        if(first[i]==last[i]) {
            newS+= first[i];
        }
        else return newS ;

    }
    return newS;
}
int main(){
    //[flower,flow,flight]
    vector<string> str;
    str.push_back("flower");
    str.push_back("flow");
    str.push_back("flight");
    
    cout<<longestcommonprefix(str);

}