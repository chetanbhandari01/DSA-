#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int binary_to_deciaml(string &binary){
    int n=binary.size();
    int result=0;
    int t=1;
    for(int i=n-1;i>=0;i--){
        char ch=binary[i];
        int num=ch - '0';   //ch=1 cha ascii=49 and '0' ascii value=48 than 49-48=1 hoga
        result+=num*t;
        t=t*2;
    }
    return result ;
}
int main(){
    string str="001000";
    cout<<binary_to_deciaml(str);
}