#include<iostream>
#include<unordered_set>
#include<vector>
#include<queue>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>>q;
    unordered_set<string>st(wordList.begin(),wordList.end());
    q.push({beginWord,1});
    st.erase(beginWord);
    while(q.size()>0){
        string word = q.front().first;
        int step = q.front().second;
        q.pop();
        if(word == endWord) return step;
        for(int i=0;i<word.size();i++){
            char original = word[i];  
            for(char ch ='a';ch<='z';ch++){
                word[i] = ch;
                //check for exist in set 
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,step+1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main() {

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot","dot","dog","lot","log","cog"
    };

    int result = ladderLength(beginWord, endWord, wordList);

    cout << "Length of shortest transformation sequence: "
         << result << endl;

    return 0;
}