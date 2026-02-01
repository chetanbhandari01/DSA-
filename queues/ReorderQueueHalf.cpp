//reorder queue (interleave 1st half with 2nd half)Do this by using one stack only
//even lenght
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reorderHalf(queue<int>&q){
    int n=q.size();
    stack<int>st;
    //first half in stack
    for(int i=1;i<=n/2;i++){
        st.push(q.front());
        q.pop();
    }
    //empty the st into q
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
    //second half in stack
    for(int i=1;i<=n/2;i++){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){  //imp
        q.push(st.top());
        st.pop(); 
        q.push(q.front());
        q.pop();
    }
    //saare element queue me hai but order me nahi hai tu reverse hai
    while(q.size()>0){
        st.push(q.front());
        q.pop();
    }
    while(st.size()>0){
        q.push(st.top());
        st.pop();
    }
}
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
int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50); 
    q.push(60);
    q.push(70); 
    q.push(80);
    display(q);
    reorderHalf(q);
    display(q);
}