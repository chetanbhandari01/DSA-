#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
using namespace std;
unordered_map<string,int>mp;
vector<vector<string>>ans;
string b ;
void dfs(string word,vector<string>&seq){
    if(word == b){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        reverse(seq.begin(),seq.end());
        return;
    }
    int step = mp[word];
    for(int i=0;i<word.size();i++){
        char original = word[i];
        for(char ch ='a';ch<='z';ch++){
            word[i] =ch;
            if(mp.find(word)!=mp.end() && mp[word]+1 == step){
                seq.push_back(word);
                dfs(word,seq);
                seq.pop_back();
            }
        }
        word[i] = original;
    }

}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    queue<string>q;
    unordered_set<string>st(wordList.begin(),wordList.end());
    st.erase(beginWord);
    q.push({beginWord});
    mp[beginWord] =1;
    b = beginWord;
    int sz = beginWord.size();
    while(q.size()>0){
        string word = q.front();
        int step = mp[word];
        q.pop();
        if(word==endWord) break;
        for(int i=0;i<sz;i++){
            char original = word[i];
            for(char ch = 'a';ch<='z';ch++){
                word[i] = ch;
                if(st.count(word)>0){
                    q.push(word);
                    st.erase(word);
                    mp[word] = step+1;
                }
            }
            word[i] = original;
        }
    }
    if(mp.find(endWord) != mp.end()){
        vector<string>seq;
        seq.push_back(endWord);
        dfs(endWord,seq);
    }
    return ans;
}
int main() {

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot","dot","dog","lot","log","cog"
    };

    vector<vector<string>>result = findLadders(beginWord, endWord, wordList);

    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[0].size();j++ ){
            cout<<result[i][j]<< " ";
        }
        cout<<endl;
    }

    return 0;
}