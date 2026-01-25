#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
string RemoveDuplicate(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(st.size()==0){
            st.push(s[i]);
        }
        else {
            if(st.top()!=s[i]){
                st.push(s[i]);
            }
        }
    }
    s="";
    while(st.size()>0){
        s +=st.top();
        st.pop();
    }
    reverse(s.begin(),s.end());
    return s ;

}
int main(){
    string s="aaabbcddaabgg";
    cout<<RemoveDuplicate(s);
}