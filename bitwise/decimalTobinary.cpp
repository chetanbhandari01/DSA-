#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
string deciaml_to_binary(int num){
    string result="";
    while(num>0){
        if(num%2==0){
            //even
            result="0"+result;
        }
        else{ //odd
            result ="1"+result;
        }
        num=num/2;
    }
    return result;
}
int main(){
    int num=8;
    cout<<deciaml_to_binary(num);
}


// int main(){
//     int n=11;
//     int sum;
//     while(n>0){
//         sum =n%2;
//         n=n/2;
//         cout<<sum;
//     }
    
// }