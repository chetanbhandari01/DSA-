#include<iostream>
#include<queue>
using namespace std;
int main(){
    vector<int>arr={3,2,1,5,4,3,2};
    priority_queue<int ,vector<int>,greater<int>>pq;
    int k=2;
    for(int i=0;i<arr.size();i++){
        pq.push(arr[i]);
        if(pq.size()>k)pq.pop();
    }
    cout<<pq.top();
}