#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string t;
        cin>>t;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s!=t){
            cout<<"NO"<<endl;
        }
        
        else if(s==t){
            cout<<"YES"<<endl;
        } 
    }
}