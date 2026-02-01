#include<iostream>
#include<stack>
using namespace std;
int prio(char ch){
    if(ch=='+' || ch=='-') return 1;
    else return 2;
}
int solve(int val1,int val2,int ch){
    if(ch=='+') return val1+val2;
    else if(ch=='-') return val1-val2;
    else if(ch=='*') return val1*val2;
    else  return val1/val2;
}
int main(){
    string str="(2+6)*4/8-3";
    stack<int >val;
    stack<char>op;
    for(int i=0;i<str.size();i++){
        //check if s[i] is a digit 0-9
        if(str[i]>=48 && str[i]<=57){
            val.push(str[i]-48);
        }
        else{  // not a digit ->* / + -
            if(op.size()==0)  op.push(str[i]);
            else if(prio(str[i])>prio(op.top())){
                op.push(str[i]);
            }
            else{ //work priority s[i]<=priority(op.top())
                while(op.size()>0 && prio(str[i])<=prio(op.top())){
                    //i have to do val1 op val2
                    char ch=op.top();
                    op.pop();
                    int val2=val.top();
                    val.pop();
                    int val1=val.top();
                    val.pop();
                    int ans=solve(val1,val2,ch);
                    val.push(ans);
                }
                op.push(str[i]);
            }
        }
    }
    //the operator stack can hav values
    //so make it empty
    while(op.size()>0){
        //i have to do val1 op val2
        char ch=op.top();
        op.pop();
        int val2=val.top();
        val.pop();
        int val1=val.top();
        val.pop();
        int ans=solve(val1,val2,ch);
        val.push(ans);
    }
    cout<<val.top();
}