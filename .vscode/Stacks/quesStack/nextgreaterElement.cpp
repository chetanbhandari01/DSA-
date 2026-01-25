#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    int arr[]={3,1,2,5,4,6,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ngt[n-1];  //reverse travel karna
    ngt[n-1]=-1;
    stack<int>st;
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        //pop all the element smaller than arr[i]
        while(st.size()>0 && arr[i]>=st.top()) {
            st.pop();
        }
        //mark the ans in ngt array
        if(st.size()==0) ngt[i]=-1;
        else ngt[i]=st.top();

        //push arr[i]
        st.push(arr[i]);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<ngt[i]<<" ";
    }
}