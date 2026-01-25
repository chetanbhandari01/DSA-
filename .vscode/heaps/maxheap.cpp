#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>pq;
    pq.push(1);
    pq.push(10);
    pq.push(-2);
    cout<<pq.top();
}
