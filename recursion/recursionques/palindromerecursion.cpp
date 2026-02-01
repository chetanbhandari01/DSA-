#include<iostream>
#include<string>
using namespace std;
bool palindrome(string s,int i,int j){
    if(i>j) return true;  //base condition 
    if(s[i]!=s[j]) return false;  
    else return palindrome(s,i+1,j-1);   //calling function
    
}
int main(){
    string s="racecar";
    cout<<palindrome(s,0,s.size()-1);
}