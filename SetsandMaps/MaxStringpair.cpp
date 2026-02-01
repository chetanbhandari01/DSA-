#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
int stringPair(vector<string>& words){
    int n=words.size();
    unordered_set<string>s;
    int count=0;
    for(int i=0;i<words.size();i++){
        string rev=words[i];
        reverse(rev.begin(),rev.end());
        if(s.find(rev)==s.end()){
            s.insert(words[i]);
        }
        else count++;
    }
    return count;
}
int main(){
    vector<string>str={"ac","ca","cd","dc"};
    cout<<stringPair(str);
}