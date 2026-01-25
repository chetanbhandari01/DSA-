#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>st;
    st.push(10);  //1
    st.push(20);  //2
    st.push(30);  //3
    st.push(40);  //4

    stack<int >temp;  //we will use extra stack
    while(st.size()>0){    //printing in reverse order 
        cout<<st.top()<<" ";
        int x=st.top(); 
        st.pop();
        temp.push(x);
    }
    ////putting elements back from temp to st
    while(temp.size()>0){
        st.push(temp.top());   //instead of intial int directly push 
        temp.pop();
    }
    cout<<endl;
    cout<<st.top();

}