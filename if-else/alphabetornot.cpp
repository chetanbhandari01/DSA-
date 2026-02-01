//write a progrsm to check whether a character is an alphabet or not 
#include<iostream>
using namespace std ;
int main(){
    char ch;
    cout<<"enter a character : ";
    cin>>ch;
    int num;
    num=(int)ch;
    if(num>=97 && num<=122){
        cout<<"the character is alphabet";
    }
    else if(num>=65 && num<=90){
        cout<<"the character is alphabet";
    }
    else{
        cout<<"not character";
    }
}