#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int>ans;
    unordered_map<int,int>m;
    for(int ele :digits){
        m[ele]++;
    }
    for(int i=100;i<=999;i+=2){
        int x=i;
        int a=x%10;
        x/=10;
        int b=x%10;
        x/=10;
        int c=x;
        if(m.find(a)!=m.end()){
            m[a]--;
            if(m[a]==0) m.erase(a);
            if(m.find(b)!=m.end()){
                m[b]--;
                if(m[b]==0) m.erase(b);
                if(m.find(c)!=m.end()){
                    ans.push_back(i);
                }
                m[b]++;
            }
            m[a]++;
        }
    }
    return ans;
}
int main(){
    vector<int>v={2,3,1,0};
    vector<int>ans=findEvenNumbers(v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}