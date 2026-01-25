#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
string repeatLimitedString(string s, int repeatLimit){
    unordered_map<char,int>mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    priority_queue<pair<char,int>>pq;
    for(auto p:mp){
        pq.push(p);
    }
    string result = "";
    while(pq.size()>0){
        auto largest = pq.top();
        pq.pop();
        int len = min(largest.second,repeatLimit);
        for(int i=0;i<len;i++){
            result +=largest.first;
        }
        auto secondlargest = pq.top();
        if(largest.second - len>0){
            if(!pq.empty()){
                result+=secondlargest.first;
                pq.pop();
            }
            else {
                return result;
            }
            if(secondlargest.second-1 >0) pq.push({secondlargest.first,secondlargest.second-1});
            pq.push({largest.first,largest.second-len});
        }
    }
    return result;
}
int main(){
    string s = "aababab";
    cout<<repeatLimitedString(s,2);
}