#include<iostream>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;
int makesum(long long x){
    int sum = 0;
    while(x>0){
        sum += x%10;
        x/=10;
    }
    return sum;
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long x ;
        cin>>x;
        
        int cnt=0;
        for(long long y=x;y<=x+100;y++){
            if(y-makesum(y) ==x){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }

}