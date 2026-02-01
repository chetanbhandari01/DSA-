#include<iostream>
#include<stack>
using namespace std;
class Minstack{
public: 
    stack<long long>st;
    long long min;
    Minstack(){
        min=LLONG_MAX;
    }
    void push(int val){
        long long x=(long long)val;
        if(st.size()==0 ) {
            st.push(x);
            min=x;
        }
        else if(st.top()<=x) st.push(x);
        else {
            st.push(2*x-min);
            min=x;
        }
    }
    void pop(){
        if(st.top()>=min) st.pop();
        else {
            long long oldmin= 2*min-st.top();
            min =oldmin;
            st.pop();
        }
    }
    int top(){
        if(st.top()<min) return (int)min;
        else return (int)st.top();
    }
    int minele(){
        return (int)min;
    }
};
int main(){
    Minstack st;
    st.push(2);
    st.push(9);
    st.push(6);
    st.push(1);
    st.push(4);
    st.push(8);
    st.pop();
    cout<<st.minele();

}