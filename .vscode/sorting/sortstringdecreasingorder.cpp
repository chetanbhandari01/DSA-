#include<iostream>
#include<string>
using namespace std;
//str se sirf x>=character sorted string me print karo
int main(){
    string str="AZYZXBYDXJK";
    string str1="";
    for(int i=0;i<str.length();i++){
        if(str[i]>='X'){
            str1.push_back(str[i]);
        }
    }

    //sort
    for(int i=0;i<str1.length()-1;i++){
        for(int j=0;j<str1.length()-1-i;j++){
            if(str1[j]<str1[j+1]){
                int temp=str1[j];
                str1[j]=str1[j+1];
                str1[j+1]=temp;
            }
        }
    }
    cout<<str1;  
    
}