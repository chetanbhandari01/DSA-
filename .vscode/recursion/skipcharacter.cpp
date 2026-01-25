#include<iostream>
#include<string>
using namespace std;
void removechar(string ans,string original,int idx ){
    if(idx==original.size()){
        cout<<ans;
        return;
    }
    char ch=original[idx];
    if(ch=='p') removechar(ans,original,idx+1);
    else removechar(ans+ch,original,idx+1);
}
int main(){
    string str="apple";
    removechar("",str,0);
    // string s="";
    // for(int i=0;i<str.size();i++){
    //     if(str[i]!='p') s+=str[i];      ////this is using for loop
    // }
    // cout<<s;
}