//leetcode  38 count and say
#include<iostream>
#include<string>
using namespace std;
string CountandSay(int n){
    if(n==1) return "1";
    string str=CountandSay(n-1);
    //str =3322251 -> 23 32 15 11
    string ztr="";
    int freq=1;
    char ch=str[0];
    for(int i=1;i<str.size();i++){
        char dh=str[i];
        if(ch==dh) {
            freq++;
        }
        else{  //ch!=dh
            ztr+=(to_string(freq)+ch);
            ch=dh;
            freq=1;
        }
    }
    ztr+=(to_string(freq)+ch);
    return ztr;
}
int main(){
    cout<<CountandSay(1);
}