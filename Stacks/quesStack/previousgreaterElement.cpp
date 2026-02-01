#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[]={3,1,2,5,4,6,2,3};
    int n=8;
    int pgt[n];
    pgt[0]=-1;
    stack<int>st;
    st.push(arr[0]);
    for(int i=1;i<n;i++){
        while(st.size()>0 && st.top() <= arr[i]){
            st.pop();
        }

        if(st.size()==0) pgt[i]=-1;
        else pgt[i]=st.top();

        st.push(arr[i]);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<pgt[i]<<" ";
    } 
}