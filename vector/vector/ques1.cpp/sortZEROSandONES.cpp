#include<iostream>
#include<vector>
using namespace std;
void sort01(vector<int>&v){
    int n=v.size();
 //method 1 is calculate 0 and one than if 0 are three give first three position to 0 and rest of one
 //this method is time complexity is 2n because two times loop is working.
    int count_one=0;
    int count_zero=0;
    for(int i=0;i<=n-1;i++){
        if(v[i]==0) count_zero++;
        else count_one++;
    }
    for(int i=0;i<=n-1;i++){
        if(i<count_zero) v[i]=0; 
        else v[i]=1;
    }
}
int main(){
    vector<int>v;
    int n;
    cout<<"enter size : ";
    cin>>n;
    for(int i=0;i<=n-1;i++){
        int q;
        cin>>q;
        v.push_back(q);
    }
    sort01(v);
    for(int i=0;i<=n-1;i++){
        cout<<v[i]<<" ";
    }

    
}