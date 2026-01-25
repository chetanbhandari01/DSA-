#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int isprecedence(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/')return 2;
    else if(c=='+'||c=='-')return 1;
    return -1;
}
bool isoperator(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^') ;
}
bool isRightAssociative(char c){
    return c=='^';
}
string infixTopostfix(string str){
    stack<char>st;
    string result="";
    for(int i=0;i<str.size();i++){
        char c=str[i];
        if(isalnum(c)){
            result+=c;
        }
        else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty() && st.top()!='('){
                result+=st.top();
                st.pop();
            }
            if(!st.empty())st.pop();
        }
        else if(isoperator(c)){
            while(!st.empty() && isoperator(st.top())&& (isprecedence(c)<isprecedence(st.top()) 
            ||!isRightAssociative(c) && (isprecedence(c)==isprecedence(st.top())))){
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        result+=st.top();
        st.pop();
    }
    return result;
}
int main(){
    string str="1+2*7";
    string res=infixTopostfix(str);
    cout<<res;
}