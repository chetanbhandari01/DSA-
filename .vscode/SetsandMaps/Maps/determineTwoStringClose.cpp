#include<iostream>
#include<unordered_map>
using namespace std;
bool closeStrings(string word1, string word2) {
    if(word1.size()!=word2.size())return false;
    unordered_map<char,int>m1;
    unordered_map<char,int>m2;
    for(int i=0;i<word1.size();i++){
        m1[word1[i]]++;
        m2[word2[i]]++;
    }
    for(auto x: m1){
        char ch=x.first;
        if(m2.find(ch)==m2.end()) return false;
    }
    unordered_map<int ,int>mS1;
    unordered_map<int,int>mS2;
    for(auto x: m1){ //helper 
        int freq=x.second;
        mS1[freq]++;
    }
    for(auto x: m2){ //helper 
        int freq=x.second;
        mS2[freq]++;
    }
    //conparing ms1 and ms2
    for(auto x: mS1){  
        int key =x.first;
        if(mS2.find(key)==mS2.end())return false; 
        if(mS2[key]!=mS1[key]) return false;
    }
    return true;
}
int main(){
    string s1="abc";
    string s2="bca";
    cout<<closeStrings(s1,s2);
}