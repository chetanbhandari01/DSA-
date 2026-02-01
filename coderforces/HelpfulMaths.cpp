#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string checking(string str){
    string nums="";
    if(str.size()==1) return str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='1'||str[i]=='2'||str[i]=='3'){
            nums+=str[i];
        }
        else {
            nums+=str[i-1];
        }
    }
    sort(nums.begin(),nums.end());
    for(int i=0;i<str.size();i++){
        if(str[i]=='1'||str[i]=='2'||str[i]=='3'){
            str[i]=nums[i];
        }
    }
    return str;
}
int main(){
    string str;
    cin>>str;
    string ans=checking(str);
    cout<<ans;
}