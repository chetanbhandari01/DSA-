//leetcode 60  hard permutation
//n=3  ---> 123  == 123 , 132 , 213, 231 , 312 ,321
// k=3 than kth term is 213
#include<iostream>
#include<vector>
#include<string>
using namespace std;
string helper(string str,int k,string ans){
    int n=str.size();
    if(n==0) return ans;
    int fact=1;
    for(int i=2;i<=n-1;i++){  // n ch factorial nahi n-1 ch factorial kadne
        fact*=i;
    }
    int idx=k/fact;
    if(k%fact==0) idx--;
    char ch=str[idx];
    string left=str.substr(0,idx);
    string right=str.substr(idx+1);
    int q=1;
    if(k%fact==0) q=fact;
    else q=k%fact;
    return helper(left+right,q,ans+ch);

}
string permutation(int n,int k){
    string str="";
    for(int i=1;i<=n;i++){
        str += to_string(1);
    }
    return helper(str,k,"");
} 
int main(){
    cout<<permutation(4,14);
}