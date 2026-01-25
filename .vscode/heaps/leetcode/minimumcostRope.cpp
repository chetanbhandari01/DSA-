#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minCost(vector<int>& arr) {
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int x:arr){
        pq.push(x);
    }
    int cost=0;
    while(pq.size()>1){
        int xs=pq.top();
        pq.pop();
        int s=pq.top();
        pq.pop();
        cost +=(xs+s);
        pq.push(xs+s);
    }
    return cost;
}
int main(){
    vector<int>arr={4, 2, 7, 6, 9};
    cout<<minCost(arr);
}
