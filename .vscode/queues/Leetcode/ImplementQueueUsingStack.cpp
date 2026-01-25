#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class Queue{
public:
    stack<int>st;
    stack<int>helper;
    Queue(){

    }
    void push(int x){
        if(st.size()==0) st.push(x);
        else {
            while(st.size()>0){
                helper.push(st.top());
                st.pop();
            }
            st.push(x);
            while(helper.size()>0){
                st.push(helper.top());
                helper.pop();
            }
        }
    }
    int pop(){
        int x=st.top();
        st.pop();
        return x;
    }
    int peek(){
        return st.top();
    }
    bool empty(){
        if(st.size()==0) return true;
        else return false ;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50); 
    
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
}