#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>st;
    st.push(10);  //1
    st.push(20);  //2
    st.push(30);  //3
    st.push(40);  //4
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;  //print top element 
    // while(st.size()>0){   //printint all element 
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

}