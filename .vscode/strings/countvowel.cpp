#include<iostream>
#include<string>
using namespace std;
int main(){
    string a;
    cout<<"enter a string : ";
    getline(cin,a);
    int count=0;
    // for(int i=0;a[i]!='\0';i++){
    //     if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
    //         count++;
    //     }
        
    // }
    // cout<<count;


    //or
    int i=0;
    while (a[i]!='\0'){
        if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'){
            count++;
        }
        i++;
    }
    cout<<count;
    
    
}