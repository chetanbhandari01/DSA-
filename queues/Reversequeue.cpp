#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void display(queue<int>&q){
    int n=q.size();
    for(int i=0;i<n;i++){
        cout<<q.front()<<" ";
        int a=q.front();
        q.pop();
        q.push(a);
    }
    cout<<endl;
}
void reverse(queue<int>&q){
    stack<int>st;
    int n=q.size();
    while(q.size()>0){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
    display(q);
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    display(q);
    reverse(q);
}