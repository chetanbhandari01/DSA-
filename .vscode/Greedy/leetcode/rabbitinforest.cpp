#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int numRabbits(vector<int>& answers) { 
    int n = answers.size();
    unordered_map<int,int>mp;
    int count=0;
    for(int i=0;i<n;i++){
        if(mp[answers[i]+1] ==false){
            count +=answers[i]+1;  //
            if(answers[i]==0) continue;  //anser =0 hai tu mp me add mat karu 
            mp[answers[i]+1]=1;
        }
        else{
            mp[answers[i]+1]++;
            int key = answers[i]+1;
            int value = mp[key];
            //we found all the rabbits of the group
            //eliminaate the group
            if(key==value){
                mp.erase(key);
            }
        }
    }
    return count;
}
int main(){
    vector<int> answers = {1,0,1,0,0};
    cout<<numRabbits(answers);
}
