#include<iostream>
#include<stack>
#include<string>
using namespace std;
string solve(string val1,string val2,char ch){  //infix = val ch val2
    string s="";
    s += val1;
    s.push_back(ch);
    s += val2;
    return s;
}
int main(){
    string s="-/*+79483";
    stack<string>val;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]>=48 && s[i]<=57){
            val.push(to_string(s[i]-48));
        }
        else {
            string val1=val.top();
            val.pop();
            string val2=val.top();
            val.pop();
            string ans=solve(val1,val2,s[i]);  
            val.push(ans);  
        }
    }
    cout<<val.top();
}