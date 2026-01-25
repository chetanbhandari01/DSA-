#include<iostream>
#include<string>
using namespace std;
void printsubset(string ans,string original){
    if(original==""){
        cout<<ans<<endl;   // 8 character will print and and last one is empty string
        return;
    }
    char ch=original[0];
    printsubset(ans+ch,original.substr(1));
    printsubset(ans,original.substr(1));
    
}
int main(){
    string str="abc";
    printsubset("",str);
}


