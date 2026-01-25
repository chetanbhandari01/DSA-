#include<iostream>
#include<string>
using namespace std;
bool palindrom(string str){
    string temp=str;
    reverse(str.begin(),str.end());
    if(str==temp) return true;
    return false;
}

int main(){
    int noT;
    cin>>noT;//no of times
    for(int i=0;i<noT;i++){
        int strl;
        cin>>strl;
        string str;
        cin>>str;

    }
}