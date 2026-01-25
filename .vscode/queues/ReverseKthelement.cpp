#include<iostream>
#include<queue>
#include<stack>
using namespace std;
void reverseK(queue<int>&q,int k){
    int n=q.size();
    stack<int>st;
    for(int i=0;i<k;i++){  ///kth  element in stack
        int a=q.front();
        st.push(a);
        q.pop();
    }
    while(st.size()>0){   //stack kth element queue me push karo
        q.push(st.top());
        st.pop();
    }
    for(int i=0;i<n-k;i++){  //first n-k th element piche lagana
        int b=q.front();
        q.pop();
        q.push(b);
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
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(90);
    reverseK(q,2);
    display(q);
}