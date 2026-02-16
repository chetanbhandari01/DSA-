#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,s,x;
        cin>>n>>s>>x;
        int sum=0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            sum+=a;
        }
        if(sum==s) cout<<"YES"<<endl;
        else if(sum >s){
            cout<<"NO"<<endl;
        }
        else {
            int k = s- sum;
            if(k%x==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}