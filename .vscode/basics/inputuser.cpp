#include<iostream>
using namespace std;

//simple interest question
int main(){
    float principal;
    cout<<"enter a principal : ";
    cin>>principal;
    float interest;
    cout<<"enter a interest : ";
    cin>>interest;
    float time;
    cout<<"enter a time : ";
    cin>>time;
    float result ;
    result = (principal*interest*time)/100;
    cout<<"the result is :"<<result;
 
}