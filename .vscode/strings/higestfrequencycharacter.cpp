#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    string str="chetanbhandari";
    vector<int> arr(26,0);
    //making a vector adding values
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        int ascii=(int)ch;
        arr[ascii-97]++;
    }
    //counting 
    int max=0;
    for(int i=0;i<26;i++){
        if(max<arr[i]) max=arr[i];
    }

    //
    for(int i=0;i<26;i++){
        if(arr[i]==max) {
            int ascii=i+97;
            char ch=(char)ascii;
            cout<< ch <<" "<<max;
        }
    }


    
}