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
    while(st.size()>0){    
        cout<<st.top()<<" ";  //reverse order print kartu
        temp.push(st.top());
        st.pop();
        
    }
    cout<<endl;
    //printing in normal order
    while(temp.size()>0){
        cout<<temp.top()<<" ";
        temp.pop();
    }
}