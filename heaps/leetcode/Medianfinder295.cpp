#include<iostream>
#include<queue>
using namespace std;
class medianfinder{
public:
    priority_queue<int,vector<int>,greater<int>>right;//minheap
    priority_queue<int>left; //maxheap

    void addnum(int num){
        if(left.size()==0 || num<left.top()){
            left.push(num);
        }
        else right.push(num);
        //
        if(abs((int)left.size()-(int)right.size())>1){
            if(left.size()>right.size()){
                right.push(left.top());
                left.pop();
            }
            if(left.size()<right.size()){
                left.push(right.top());
                right.pop();
            }
        }
    }
    double median(){
        if(left.size()==right.size()){
            return (left.top()+right.top())/2.0;
        }
        else{
            if(left.size()>right.size()) return left.top();
            else return right.top();
        }
    }
};
int main(){
    medianfinder mf;
    mf.addnum(2);
    mf.addnum(5);
    mf.addnum(1);
    mf.addnum(9);
    mf.addnum(6);
    mf.addnum(7);
    cout<<mf.median();
}