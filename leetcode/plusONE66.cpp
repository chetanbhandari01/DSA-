#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v={9,9};
    //123+1=124
    int n=v.size();
    for(int i=n-1;i>=0;i--){
        if(v[i]<9){
            v[i]++;
            return v[i];
        }
        v[i]=0;
    }
    v.insert(v.begin(),1);

    for(int i=0;i<n+1;i++){
        cout<<v[i];
    }

}