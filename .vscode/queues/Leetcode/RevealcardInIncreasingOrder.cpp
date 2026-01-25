#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> deckRevealedIncreasing(vector<int>& deck){
    int n=deck.size();
    sort(deck.begin(),deck.end());
    queue<int>q;
    for(int i=0;i<n;i++){
        q.push(i);
    }
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int idx=q.front();
        q.pop();
        q.push(q.front());
        q.pop();
        ans[idx]=deck[i];
    }
    return ans;
}
int main(){
    vector<int>v={17,13,11,2,3,5,7};
    vector<int>ans={deckRevealedIncreasing(v)};
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}