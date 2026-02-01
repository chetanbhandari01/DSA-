#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    string result="";
    for(int i=0;i<str.size();i++){
        int j;
        for( j=0;j<i;j++){
            if(str[i]==str[j]) break;
        }
        if(j==i){
            result+=str[i];
        }
    }
    int a=result.size();
    if(a%2==0)  cout<<"CHAT WITH HER!";
    else cout<<"IGNORE HIM!" ;
}
