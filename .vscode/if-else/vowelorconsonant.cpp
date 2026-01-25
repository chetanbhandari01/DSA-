//vowel or consonant 
#include<iostream>
using namespace std;
int main(){
    char ch ;
    cout<<"enter a character : ";
    cin>>ch;
    if(ch=='a' || ch=='e' ||ch=='i' ||ch=='o' || ch=='u'){
        cout<<"the character is vowel";
    }
    else if(ch=='A' || ch=='E' ||ch=='I' ||ch=='O' || ch=='U'){
        cout<<"the character is vowel";
    }
    else{
        cout<<"is consonant";
    }
}