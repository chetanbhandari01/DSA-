#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    int k;
    cin>>n;
    cin>>k;
    int p;
    vector<int>score(n);
    int count=0;
    for(int i=0;i<n;i++){
        cin>>p;
        score[i]=p;
    }
    int check=score[k-1];
    for(int i=0;i<n;i++){
        if(score[i]>=check && score[i]!=0){
            count++;
        }
    }

    cout<<count;
}