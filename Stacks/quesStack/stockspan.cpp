#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    vector<int>v={100,80,60,81,70,60,75,85};
    int n=v.size();
    vector<int > pgtidx(n);
    pgtidx[0]=-1;
    stack<int>st;
    st.push(0);
    for(int i=1;i<n;i++){
        while(st.size()>0 && v[st.top()] <= v[i]){
            st.pop();
        }

        if(st.size()==0) pgtidx[i]=-1;
        else pgtidx[i]=st.top();

        st.push(i);
    }
    //actual idx - pgtidx
    for(int i=0;i<n;i++){
        pgtidx[i]=i-pgtidx[i];
    }

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<pgtidx[i]<<" ";
    }

}