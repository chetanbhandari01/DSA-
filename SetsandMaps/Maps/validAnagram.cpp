#include<iostream>
#include<unordered_map>
using namespace std;
bool validAnagram(string s,string t){
    if(s.size()!=t.size()) return false;
    unordered_map<int,int>map;
    for(int i=0;i<s.size();i++){
        map[s[i]]++;
    }
    for(int i=0;i<t.size();i++){
        if(map.find(t[i])!=map.end()){
            map[t[i]]--;
            if(map[t[i]]==0) map.erase(t[i]);
        }
        else{
            return false;
        }
    }
    if(map.size()>0) return false;
    return true;
}
int main(){
    string s="anagram";
    string t="gramnaa";
    cout<<validAnagram(s,t);
}