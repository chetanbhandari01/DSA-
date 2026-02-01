//leetcode 445
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findcookie(vector<int>& g,vector<int>& s){
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int n=g.size();
    int nn=s.size();
    int count=0;
    int i=0;
    int j=0;
    while(i<n && j<nn){
        if(g[i]<=s[j]){
            count++;
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    return count;
}
int main(){
    vector<int>g;
    vector<int>s;
    g.push_back(5);
    g.push_back(7);
    g.push_back(8);
    s.push_back(10);
    g.push_back(10);
    s.push_back(8);
    s.push_back(6);
    s.push_back(5);
    cout<<findcookie(g,s);
}