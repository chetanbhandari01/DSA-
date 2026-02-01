#include<iostream>
#include<stack>
#include<string>
using namespace std;
int prio(char ch){
    if(ch=='+' || ch=='-') return 1;
    else return 2;
}
string solve (string val1,string val2 ,char op){
    //we have to store prefix in the ans
    //prefix is ->op val1 val2
    string s="";
    s.push_back(op);
    s += val1;
    s += val2;
    return s;
}
int main(){
    string s="(7+9)*4/8-3";
    stack<string>val;
    stack<char>op;
    for(int i=0;i<s.size();i++){
        if(s[i]>=48 && s[i]<=57) {
            val.push(to_string(s[i]-48));
        }
        else{  // not a digit ->* / + - ( )
            if(op.size()==0)  op.push(s[i]);
            else if (s[i]=='(') op.push(s[i]);
            else if(op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                    //work
                    char ch=op.top();
                    op.pop();
                    string val2=val.top();
                    val.pop();
                    string val1=val.top();
                    val.pop();
                    string ans=solve(val1,val2,ch);
                    val.push(ans);
                }
                op.pop();  //opening brk ko udana
            }
            else if(prio(s[i])>prio(op.top())){
                op.push(s[i]);
            }
            else{ //work priority s[i]<=priority(op.top())
                while(op.size()>0 && prio(s[i])<=prio(op.top())){
                    //i have to do val1 op val2
                    char ch=op.top();
                    op.pop();
                    string val2=val.top();
                    val.pop();
                    string val1=val.top();
                    val.pop();
                    string ans=solve(val1,val2,ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    //the operator stack can hav values
    //so make it empty
    while(op.size()>0){
        //i have to do val1 op val2
        char ch=op.top();
        op.pop();
        string val2=val.top();
        val.pop();
        string val1=val.top();
        val.pop();
        string ans=solve(val1,val2,ch);
        val.push(ans);
    }
    cout<<val.top();
}