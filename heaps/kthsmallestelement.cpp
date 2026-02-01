#include<iostream>
#include<queue>
using namespace std;
int main(){
    vector<int>arr={4,3,7,6,1,5};
    int k=3; //means k-1 element idx 
    priority_queue<int>pq;
    for(int i=0;i<arr.size();i++){
        pq.push(arr[i]);
        if(pq.size() >k) pq.pop();
    }
    cout<<pq.top();

}