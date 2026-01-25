//2483 leetcode
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int bestClosingTime(string customers) {
    int n =customers.size();
    vector<int>prefix(n+1);  //no .of N before Kth hour
    vector<int>suffix(n+1);  //no.of Y after and including kth hour
    prefix[0]=0;
    for(int i=0;i<n;i++){
        int count=0;
        if(customers[i]=='N') count++;
        prefix[i+1]=count+prefix[i];
    }
    suffix[n]=0;
    for(int i=n-1;i>=0;i--){
        int count=0;
        if(customers[i]=='Y') count++;
        suffix[i]=suffix[i+1]+count;  
    }
    int minpen=n;
    for(int i=0;i<=n;i++){
        prefix[i]+=suffix[i];
        int pen=prefix[i];
        minpen=min(minpen,pen);
    }
    for(int i=0;i<=n;i++){
        int pen =prefix[i];
        if(pen==minpen) return i;
    }
    return n;
}
int main(){
    string customer="YYNY";
    cout<<bestClosingTime(customer);

}