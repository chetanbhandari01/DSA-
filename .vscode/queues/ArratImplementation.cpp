#include<iostream>
#include<vector>
using namespace std;
class Queue{
public: 
    int f;  //front
    int b;  //back  
    int s;  //size
    vector<int>arr;
    Queue(int size){
        f=0;
        b=0;
        s=0;
        vector<int>v(size);
        arr=v;
    }
    void push(int val){
        if(b==arr.size()){
            cout<<"queue is full ";
            return ;
        }
        arr[b]=val;
        b++;
        s++;
    }
    void pop(){
        if(s ==0){  //f-b mean size of array 
            cout<<"queue is EMPTY ";
            return;
        }
        f++;
        s--;
    }
    int top(){
        if(s ==0){  //f-b mean size of array 
            cout<<"queue is EMPTY ";
            return -1;
        }
        return arr[f];
    }
    int back(){
        if(s ==0){  //f-b mean size of array 
            cout<<"queue is EMPTY ";
            return -1;
        }
        return arr[b-1];
    }
    int size(){
        return s;
    }
    void display(){
        for(int i=f;i<b;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Queue q(5); //q(5) size declear
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50); 
    q.display();
    q.pop();
    q.display();
}