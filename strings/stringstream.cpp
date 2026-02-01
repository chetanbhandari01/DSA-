#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
int main(){
    string str="raghav is best teacher";
    stringstream str1(str);
    string temp; //
       
    while(str1>>temp){
        cout<<temp<<endl;
    }
}