#include<iostream>
#include<queue>
using namespace std;
int main(){
    //push
    //pop
    //front ->top
    //size,empty
    //back
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.back()<<endl;
    cout<<q.size()<<endl;
}