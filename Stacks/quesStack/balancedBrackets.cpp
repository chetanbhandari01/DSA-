//same as valid parentheses
#include<iostream>
#include<stack>
using namespace std;
bool isbalanced(string s){
    if(s.size()%2 != 0) return false; //size odd hai
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push('(');
        }
        else {
            if(st.size()==0) return false;
            else st.pop();   //manje size 0 nahi hai "(" pop karel
        }
    }
    if(st.size()==0) return true;  //number operning brk == closing brk
    else return false ;   //
}
int main(){
    string s="(()()))";
    cout<<isbalanced(s);
}